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
PxCapsuleController *	gController = NULL;

// two spheres for a tapered capsule and one by itself
PxClothCollisionSphere   gSpheres[3] = {
	PxClothCollisionSphere(PxVec3(0.0f, 0.3f, 1.0f), 0.3f),
	PxClothCollisionSphere(PxVec3(-0.5f, 0.2f, 0.0f), 0.2f),
	PxClothCollisionSphere(PxVec3(-1.5f, 0.2f, 0.0f), 0.2f)
};

// a tetrahedron
PxClothCollisionTriangle gTriangles[4] = {
	PxClothCollisionTriangle(PxVec3(-0.3f, 0.0f, -1.3f), PxVec3(0.3f, 0.6f, -1.3f), PxVec3(0.3f, 0.0f, -0.7f)),
	PxClothCollisionTriangle(PxVec3(0.3f, 0.6f, -1.3f), PxVec3(-0.3f, 0.6f, -0.7f), PxVec3(0.3f, 0.0f, -0.7f)),
	PxClothCollisionTriangle(PxVec3(-0.3f, 0.6f, -0.7f), PxVec3(-0.3f, 0.0f, -1.3f), PxVec3(0.3f, 0.0f, -0.7f)),
	PxClothCollisionTriangle(PxVec3(-0.3f, 0.0f, -1.3f), PxVec3(-0.3f, 0.6f, -0.7f), PxVec3(0.3f, 0.6f, -1.3f)),
};

PxPlane gPlanes[5] = {
	PxPlane(PxVec3(0.0f,  1.0f,  0.0f),  0.0f),
	PxPlane(PxVec3(-1.0f, -1.0f,  0.0f),  1.0f),
	PxPlane(PxVec3(1.0f, -1.0f,  0.0f), -1.0f),
	PxPlane(PxVec3(0.0f,  1.0f, -1.0f), -0.5f),
	PxPlane(PxVec3(0.0f,  1.0f,  1.0f), -0.5f),
};


PxCloth*				 gCloth = NULL;
PxTransform gPose = PxTransform(PxVec3(0), PxQuat(PxPi / 4, PxVec3(0, 1, 0))) * PxTransform(PxVec3(1, 0.5f, 0));

void createCloth()
{
	// create regular mesh
	PxU32 resolution = 10;
	PxU32 numParticles = resolution*resolution;
	PxU32 numQuads = (resolution - 1)*(resolution - 1);

	// create particles
	PxClothParticle* particles = new PxClothParticle[numParticles];
	PxVec3 center(0.5f, 0.3f, 0.0f);
	PxVec3 delta = 1.0f / (resolution - 1) * PxVec3(1.0f, 0.8f, 0.6f);
	PxClothParticle* pIt = particles;
	for (PxU32 i = 0; i<resolution; ++i)
	{
		for (PxU32 j = 0; j<resolution; ++j, ++pIt)
		{
			pIt->invWeight = j + 1<resolution ? 1.0f : 0.0f;
			pIt->pos = delta.multiply(PxVec3(PxReal(i),
				PxReal(j), -PxReal(j))) - center;
		}
	}

	// create quads
	PxU32* quads = new PxU32[4 * numQuads];
	PxU32* iIt = quads;
	for (PxU32 i = 0; i<resolution - 1; ++i)
	{
		for (PxU32 j = 0; j<resolution - 1; ++j)
		{
			*iIt++ = (i + 0)*resolution + (j + 0);
			*iIt++ = (i + 1)*resolution + (j + 0);
			*iIt++ = (i + 1)*resolution + (j + 1);
			*iIt++ = (i + 0)*resolution + (j + 1);
		}
	}

	// create fabric from mesh
	PxClothMeshDesc meshDesc;
	meshDesc.points.count = numParticles;
	meshDesc.points.stride = sizeof(PxClothParticle);
	meshDesc.points.data = particles;
	meshDesc.invMasses.count = numParticles;
	meshDesc.invMasses.stride = sizeof(PxClothParticle);
	meshDesc.invMasses.data = &particles->invWeight;
	meshDesc.quads.count = numQuads;
	meshDesc.quads.stride = 4 * sizeof(PxU32);
	meshDesc.quads.data = quads;

	// cook fabric
	PxClothFabric* fabric = PxClothFabricCreate(*gPhysics, meshDesc, PxVec3(0, 1, 0));

	delete[] quads;

	// create cloth and add to scene
	gCloth = gPhysics->createCloth(gPose, *fabric, particles, PxClothFlags(0));
	gScene->addActor(*gCloth);

	fabric->release();
	delete[] particles;

	// 240 iterations per/second (4 per-60hz frame)
	gCloth->setSolverFrequency(240.0f);

	// add virtual particles
	PxU32* indices = new PxU32[4 * 4 * numQuads];
	PxU32* vIt = indices;
	for (PxU32 i = 0; i<resolution - 1; ++i)
	{
		for (PxU32 j = 0; j<resolution - 1; ++j)
		{
			*vIt++ = i*resolution + j;
			*vIt++ = i*resolution + (j + 1);
			*vIt++ = (i + 1)*resolution + (j + 1);
			*vIt++ = 0;

			*vIt++ = i*resolution + (j + 1);
			*vIt++ = (i + 1)*resolution + (j + 1);
			*vIt++ = (i + 1)*resolution + j;
			*vIt++ = 0;

			*vIt++ = (i + 1)*resolution + (j + 1);
			*vIt++ = (i + 1)*resolution + j;
			*vIt++ = i*resolution + j;
			*vIt++ = 0;

			*vIt++ = (i + 1)*resolution + j;
			*vIt++ = i*resolution + j;
			*vIt++ = i*resolution + (j + 1);
			*vIt++ = 0;
		}
	}

	// barycentric weights specifying virtual particle position
	PxVec3 weights = PxVec3(0.6, 0.2, 0.2);
	gCloth->setVirtualParticles(4 * numQuads, indices, 1, &weights);

	delete[] indices;

	// add capsule (referencing spheres[0] and spheres[1] added later)
	gCloth->addCollisionCapsule(1, 2);

	// add ground plane and tetrahedron convex (referencing planes added later)
	gCloth->addCollisionConvex(0x01);
	gCloth->addCollisionConvex(0x1e);
}

// add modification contact
class MyContactModification : public PxContactModifyCallback
{
		void onContactModify(PxContactModifyPair* const pairs, PxU32 count);
};
void MyContactModification::onContactModify(PxContactModifyPair *const pairs, PxU32 count)
{
	for (PxU32 i = 0; i < count; i++)
	{
		const PxRigidActor** actors = pairs[i].actor;
		const PxShape** shapes = pairs[i].shape;
		pairs[i].contacts.setInvMassScale1(0.f);

		//Search for actors that represent vehicles and shapes that represent wheels.
		for (PxU32 j = 0; j < 2; j++)
		{
			const PxActor* actor = actors[j];
		}
	}
}

MyContactModification gModContactReportCallback;


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
		| PxPairFlag::eNOTIFY_CONTACT_POINTS
		| PxPairFlag::eMODIFY_CONTACTS;
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
			//printf("Trigger:%d-%d\n", pairs[i].otherShape, pairs[i].triggerShape);
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

void MoveCharacter(unsigned char key)
{
	float x = 0.f, z = 0.f;
	switch (key)
	{
	case 'a':
		x = -1.0f;
		break;
	case 's':
		z = 1.0f;
		break;
	case 'w':
		z = -1.0f;
		break;
	case 'd':
		x = 1.0f;
		break;
	}
	gController->move(PxVec3(x, 0.f, z), 0.01f, 0.1f, PxControllerFilters());

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

	createChain(PxTransform(PxVec3(10.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createLimitedSpherical);
	createChain(PxTransform(PxVec3(0.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createBreakableFixed);
	createChain(PxTransform(PxVec3(-10.0f, 30.0f, -30.0f)), 5, PxBoxGeometry(2.0f, 0.5f, 0.5f), 4.0f, createDampedD6);

	createCloth();

	// create a character controller actor
	PxControllerManager* manager = PxCreateControllerManager(*gScene);

	// create and fill in the descriptor for the capsule controller
	PxCapsuleControllerDesc cDesc;

	cDesc.height = 2.0f;
	cDesc.radius = 0.5f;
	cDesc.material = gMaterial;
	cDesc.position = PxExtendedVec3(0, 1.5, 0);
	cDesc.slopeLimit = 0.1f;
	cDesc.contactOffset = 0.01f;
	cDesc.stepOffset = 0.1f;
	cDesc.scaleCoeff = 0.9f;
	cDesc.climbingMode = PxCapsuleClimbingMode::eEASY;
	cDesc.invisibleWallHeight = 0.0f;
	cDesc.maxJumpHeight = 2.0f;
	//cDesc.reportCallback = this;

	gController = static_cast<PxCapsuleController*>(manager->createController(cDesc));
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
	sceneDesc.simulationEventCallback = &gContactReportCallback;	// contact callback
	sceneDesc.contactModifyCallback = &gModContactReportCallback;	// modification contact callback
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

	gScene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eACTOR_AXES, 1.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 2.0f);
	gScene->setVisualizationParameter(PxVisualizationParameter::eCONTACT_NORMAL, 2.0f);
}
// release PhysX
void ShutdownPhysX() {
	gCloth->release();
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

	// update the cloth local frame
	gPose = PxTransform(PxVec3(0), PxQuat(PxPi / 240, PxVec3(0, 1, 0))) * gPose;
	gCloth->setTargetPose(gPose);

	// transform colliders into local cloth space
	PxTransform invPose = gPose.getInverse();

	// 1 sphere plus 1 capsule made from two spheres
	PxClothCollisionSphere spheres[3];
	for (int i = 0; i<3; ++i)
	{
		spheres[i].pos = invPose.transform(gSpheres[i].pos);
		spheres[i].radius = gSpheres[i].radius;
	}
	gCloth->setCollisionSpheres(spheres, 3);

	// tetrahedron made from 4 triangles
	PxClothCollisionTriangle triangles[4];
	for (int i = 0; i<4; ++i)
	{
		triangles[i].vertex0 = invPose.transform(gTriangles[i].vertex0);
		triangles[i].vertex1 = invPose.transform(gTriangles[i].vertex1);
		triangles[i].vertex2 = invPose.transform(gTriangles[i].vertex2);
	}
	gCloth->setCollisionTriangles(triangles, 4);

	// tetrahedron made from 4 planes
	PxPlane planes[5];
	for (int i = 0; i<5; ++i)
	{
		planes[i] = invPose.transform(gPlanes[i]);
	}
	gCloth->setCollisionPlanes(reinterpret_cast<const PxClothCollisionPlane*>(planes), 5);

	gScene->simulate(timeStep);
	gScene->fetchResults(true);
}