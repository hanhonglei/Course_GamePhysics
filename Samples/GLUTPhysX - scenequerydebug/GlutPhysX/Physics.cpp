#include "stdafx.h"


/*Global PhyX related parameters*/
PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;
PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics = NULL;
PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene = NULL;
PxMaterial*				gMaterial = NULL;
PxPvd*                  gPvd = NULL;

PxFilterFlags contactReportFilterShader(PxFilterObjectAttributes attributes0, PxFilterData filterData0,
	PxFilterObjectAttributes attributes1, PxFilterData filterData1,
	PxPairFlags& pairFlags, const void* constantBlock, PxU32 constantBlockSize)
{
	PX_UNUSED(attributes0);
	PX_UNUSED(attributes1);
	PX_UNUSED(filterData0);
	PX_UNUSED(filterData1);
	PX_UNUSED(constantBlockSize);
	PX_UNUSED(constantBlock);

	// all initial and persisting reports for everything, with per-point data
	pairFlags = PxPairFlag::eSOLVE_CONTACT | PxPairFlag::eDETECT_DISCRETE_CONTACT
		| PxPairFlag::eNOTIFY_TOUCH_FOUND
		| PxPairFlag::eNOTIFY_TOUCH_PERSISTS
		| PxPairFlag::eNOTIFY_CONTACT_POINTS;
	return PxFilterFlag::eDEFAULT;
}

class ContactReportCallback : public PxSimulationEventCallback
{
	void onConstraintBreak(PxConstraintInfo* constraints, PxU32 count) { PX_UNUSED(constraints); PX_UNUSED(count); }
	void onWake(PxActor** actors, PxU32 count) { PX_UNUSED(actors); PX_UNUSED(count); }
	void onSleep(PxActor** actors, PxU32 count) { PX_UNUSED(actors); PX_UNUSED(count); }
	void onTrigger(PxTriggerPair* pairs, PxU32 count) {
		PX_UNUSED(pairs); PX_UNUSED(count); 
		for (PxU32 i = 0; i < count; i++)
		{
			// ignore pairs when shapes have been deleted
			if (pairs[i].flags & (PxTriggerPairFlag::eREMOVED_SHAPE_TRIGGER |
				PxTriggerPairFlag::eREMOVED_SHAPE_OTHER))
				continue;
			printf("Trigger:%d-%d\n", pairs[i].otherShape, pairs[i].triggerShape);

			// 利用userdata，确定子弹进入的话，在进入位置，生成一个新的物体
			//if (pairs[i].otherActor->userData != "bullet")
			//	return;
			//PxRigidDynamic* current = PxCreateDynamic(*gPhysics, pairs[i].otherActor->getGlobalPose(), PxBoxGeometry(0.5f, 0.5f, 0.5f), *gMaterial, 1.0f);
			//gScene->addActor(*current);

		}
	}
	void onAdvance(const PxRigidBody*const*, const PxTransform*, const PxU32) {}
	void onContact(const PxContactPairHeader& pairHeader, const PxContactPair* pairs, PxU32 nbPairs)
	{
		PX_UNUSED((pairHeader));
		std::vector<PxContactPairPoint> contactPoints;

		for (PxU32 i = 0; i<nbPairs; i++)
		{
			PxU32 contactCount = pairs[i].contactCount;

			if (contactCount)
			{
				contactPoints.resize(contactCount);
				pairs[i].extractContacts(&contactPoints[0], contactCount);
				//for (PxU32 j = 0; j<contactCount; j++)
				//	printf("(%f,%f,%f)\n", contactPoints[j].position.x, contactPoints[j].position.y
				//		, contactPoints[j].position.z);
				//for (PxU32 j = 0; j<contactCount; j++)
				//{
				//	gContactPositions.push_back(contactPoints[j].position);
				//	gContactImpulses.push_back(contactPoints[j].impulse);
				//}
			}
		}
	}
};

ContactReportCallback gContactReportCallback;

PxRigidDynamic* createDynamic(const PxTransform& t, const PxGeometry& geometry, const PxVec3& velocity = PxVec3(0))
{
	PxRigidDynamic* dynamic = PxCreateDynamic(*gPhysics, t, geometry, *gMaterial, 10.0f);
	dynamic->setAngularDamping(0.5f);
	dynamic->setLinearVelocity(velocity);
	gScene->addActor(*dynamic);
	return dynamic;
}

// spherical joint limited to an angle of at most pi/4 radians (45 degrees)
PxJoint* createLimitedSpherical(PxRigidActor* a0, const PxTransform& t0, PxRigidActor* a1, const PxTransform& t1)
{
	PxSphericalJoint* j = PxSphericalJointCreate(*gPhysics, a0, t0, a1, t1);
	j->setLimitCone(PxJointLimitCone(PxPi / 4, PxPi / 4, 0.05f));
	j->setSphericalJointFlag(PxSphericalJointFlag::eLIMIT_ENABLED, true);
	return j;
}

// revolute joint limited to an angle of at most pi/4 radians (45 degrees)

// fixed, breakable joint
PxJoint* createBreakableFixed(PxRigidActor* a0, const PxTransform& t0, PxRigidActor* a1, const PxTransform& t1)
{
	PxFixedJoint* j = PxFixedJointCreate(*gPhysics, a0, t0, a1, t1);
	j->setBreakForce(100000, 10000000);
	j->setConstraintFlag(PxConstraintFlag::eDRIVE_LIMITS_ARE_FORCES, true);
	return j;
}

// D6 joint with a spring maintaining its position
PxJoint* createDampedD6(PxRigidActor* a0, const PxTransform& t0, PxRigidActor* a1, const PxTransform& t1)
{
	PxD6Joint* j = PxD6JointCreate(*gPhysics, a0, t0, a1, t1);
	j->setMotion(PxD6Axis::eSWING1, PxD6Motion::eFREE);
	j->setMotion(PxD6Axis::eSWING2, PxD6Motion::eFREE);
	j->setMotion(PxD6Axis::eTWIST, PxD6Motion::eFREE);
	j->setDrive(PxD6Drive::eSLERP, PxD6JointDrive(0, 1000, FLT_MAX, true));
	return j;
}

typedef PxJoint* (*JointCreateFunction)(PxRigidActor* a0, const PxTransform& t0, PxRigidActor* a1, const PxTransform& t1);

// create a chain rooted at the origin and extending along the x-axis, all transformed by the argument t.

void createChain(const PxTransform& t, PxU32 length, const PxGeometry& g, PxReal separation, JointCreateFunction createJoint)
{
	PxVec3 offset(separation / 2, 0, 0);
	PxTransform localTm(offset);
	PxRigidDynamic* prev = NULL;

	for (PxU32 i = 0; i<length; i++)
	{
		PxRigidDynamic* current = PxCreateDynamic(*gPhysics, t*localTm, g, *gMaterial, 1.0f);
		(*createJoint)(prev, prev ? PxTransform(offset) : t, current, PxTransform(-offset));
		gScene->addActor(*current);
		prev = current;
		localTm.p.x += separation;
	}
}


// add a bullet in the scene
void AddBullet(const PxVec3& pos, const PxVec3& v)
{
	PxShape *shape = gPhysics->createShape(PxSphereGeometry(0.3f), *gMaterial);
	PxTransform localTmS(pos);
	PxRigidDynamic *body = gPhysics->createRigidDynamic(localTmS);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 100.0f);
	body->setLinearVelocity(v);
	gScene->addActor(*body);

	// 为子弹物体添加一个userdata，让外部得知这个物体是特殊的子弹物体
	//body->userData = "bullet";

	shape->release();
}

// add some physics objects into the scene
void AddPhyObjects()
{
	PxRigidStatic* groundPlane = PxCreatePlane(*gPhysics, PxPlane(0, 1, 0, 0), *gMaterial);
	gScene->addActor(*groundPlane);

	PxShape* shape = gPhysics->createShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *gMaterial);
	PxTransform localTm(PxVec3(-3.0f, 5.0f, 0.f));
	PxRigidDynamic* body = gPhysics->createRigidDynamic(localTm);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);

	shape->release();

	shape = gPhysics->createShape(PxSphereGeometry(1.0f), *gMaterial);
	PxTransform localTmS(PxVec3(3.0f, 5.0f, 0.f));
	body = gPhysics->createRigidDynamic(localTmS);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);

	shape->release();

	PxRigidDynamic* dynamic = PxCreateDynamic(*gPhysics, PxTransform(PxVec3(0, 20, 20)), PxSphereGeometry(1), *gMaterial, 10.0f);
	dynamic->setAngularDamping(0.5f);
	dynamic->setLinearVelocity(PxVec3(0, -5, -10));
	gScene->addActor(*dynamic);

	// add capsule into the scene
	shape = gPhysics->createShape(PxCapsuleGeometry(1.0f, 3.0f), *gMaterial);
	PxTransform localTmC(PxVec3(3.0f, 5.0f, -3.f));
	body = gPhysics->createRigidDynamic(localTmC);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);

	// add a static box as the trigger
	shape = gPhysics->createShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *gMaterial);
	PxTransform localTmTrigger(PxVec3(0.0f, 1.0f, -10.f));
	body = gPhysics->createRigidDynamic(localTmTrigger);
	shape->setFlag(PxShapeFlag::eSIMULATION_SHAPE, false);
	shape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);
	body->attachShape(*shape);
	body->setRigidBodyFlag(PxRigidBodyFlag::eKINEMATIC, true);
	gScene->addActor(*body);

	shape->release();
}

// Set up PhysX
void InitializePhysX() {
	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate("127.0.0.1", 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true, gPvd);

	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader/*PxDefaultSimulationFilterShader*/;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	PxPvdSceneClient* pvdClient = gScene->getScenePvdClient();
	if (pvdClient)
	{
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);
	}
	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// add some physics objects
	AddPhyObjects();

	createChain(PxTransform(PxVec3(10.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createLimitedSpherical);
	createChain(PxTransform(PxVec3(0.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createBreakableFixed);
	createChain(PxTransform(PxVec3(-10.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createDampedD6);

	gScene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eACTOR_AXES, 1.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 2.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eCONTACT_NORMAL, 2.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eJOINT_LIMITS, 1.0f);

}
// release PhysX
void ShutdownPhysX() {
	gScene->release();
	gDispatcher->release();
	gPhysics->release();
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();

	gFoundation->release();
}
// update PhysX
void stepPhysics(PxReal timeStep)
{
	if (timeStep <= 0)
		return;
	gScene->simulate(timeStep);
	gScene->fetchResults(true);
}