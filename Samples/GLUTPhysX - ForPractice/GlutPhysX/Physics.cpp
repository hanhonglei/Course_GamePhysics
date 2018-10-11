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

void AddNewActor()
{
	// box类型物理体
	PxShape* shape = gPhysics->createShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *gMaterial);
	PxTransform localTm(PxVec3(-3.0f, 5.0f, -15.f));
	PxRigidDynamic* body = gPhysics->createRigidDynamic(localTm);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);
}

// add some physics objects into the scene
// 使用不同的方法在场景中添加物理几何体
void AddPhyObjects()
{
	// 地面
	PxRigidStatic* groundPlane = PxCreatePlane(*gPhysics, PxPlane(0, 1, 0, 0), *gMaterial);
	gScene->addActor(*groundPlane);
	// box类型物理体
	PxShape* shape = gPhysics->createShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *gMaterial);
	PxTransform localTm(PxVec3(-3.0f, 5.0f, -15.f));
	PxRigidDynamic* body = gPhysics->createRigidDynamic(localTm);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);

	shape->release();
	// sphere类型几何体
	shape = gPhysics->createShape(PxSphereGeometry(1.0f), *gMaterial);
	PxTransform localTmS(PxVec3(3.0f, 5.0f, -15.f));
	body = gPhysics->createRigidDynamic(localTmS);
	body->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*body, 10.0f);
	gScene->addActor(*body);

	shape->release();
	// sphere类型几何体，使用直接的方式添加
	PxRigidDynamic* dynamic = PxCreateDynamic(*gPhysics, PxTransform(PxVec3(-3, 20, 20)), PxSphereGeometry(1), *gMaterial, 10.0f);
	dynamic->setAngularDamping(0.5f);
	dynamic->setLinearVelocity(PxVec3(0, -5, -10));
	gScene->addActor(*dynamic);
}

// Set up PhysX
void InitializePhysX() {
	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);
	// 初始化pvd
	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate("127.0.0.1", 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);
	// 初始化sdk代理
	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true);
	// 添加一个scene
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = PxDefaultSimulationFilterShader;
	gScene = gPhysics->createScene(sceneDesc);

	PxPvdSceneClient* pvdClient = gScene->getScenePvdClient();
	if (pvdClient)
	{
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);
	}
	// 设置一个全局的物理材质
	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// add some physics objects
	AddPhyObjects();
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