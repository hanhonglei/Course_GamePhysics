// GlutPhysX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "freeglut\include\GL\freeglut.h"
#include "foundation/PxFoundationVersion.h"
#include "foundation/Px.h"
#include "extensions/PxDefaultAllocator.h"

#include "PxPhysXConfig.h"
#include "foundation/PxMemory.h"
#include "extensions/PxDefaultErrorCallback.h"
#include "cudamanager/PxCudaContextManager.h"
#include "gpu/PxGpu.h"
#include "PxPhysicsVersion.h"
#include "PxPhysics.h"
#include "common/PxTolerancesScale.h"
#include "PxSceneDesc.h"
#include "extensions/PxDefaultCpuDispatcher.h"
#include "cooking/pxcooking.h"

//#include "PxTkFile.h"
//#include "PsString.h"
//#include "PsFPU.h"
//
//#include "PxToolkit.h"
#include "extensions/PxDefaultStreams.h"

#pragma comment(lib, "freeglut.lib")

using namespace physx;

#if PX_WINDOWS
// Starting with Release 302 drivers, application developers can direct the Optimus driver at runtime to use the High Performance
// Graphics to render any application; even those applications for which there is no existing application profile.
// They can do this by exporting a global variable named PxOptimusEnablement.
// A value of 0x00000001 indicates that rendering should be performed using High Performance Graphics.
// A value of 0x00000000 indicates that this method should be ignored.
extern "C"
{
	_declspec(dllexport) DWORD PxOptimusEnablement = 0x00000001;
}
#endif

static bool gRecook = false;
PxDefaultAllocator gDefaultAllocatorCallback;


const int	WINDOW_WIDTH = 1024,
WINDOW_HEIGHT = 768;


//for mouse dragging
int oldX = 0, oldY = 0;
float rX = 15, rY = 0;
float fps = 0;
int startTime = 0;
int totalFrames = 0;
int state = 1;
float dist = -5;

void SetOrthoForFont()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
	glScalef(1, -1, 1);
	glTranslatef(0, -WINDOW_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void ResetPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void RenderSpacedBitmapString(
	int x,
	int y,
	int spacing,
	void *font,
	char *string)
{
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2i(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c) + spacing;
	}
}


void DrawAxes()
{
	//To prevent the view from disturbed on repaint
	//this push matrix call stores the current matrix state
	//and restores it once we are done with the arrow rendering
	glPushMatrix();
	glColor3f(0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, 0.8f);
	glutSolidCone(0.0325, 0.2, 4, 1);
	//Draw label			
	glTranslatef(0, 0.0625, 0.225f);
	RenderSpacedBitmapString(0, 0, 0, GLUT_BITMAP_HELVETICA_10, "Z");
	glPopMatrix();
	glutSolidCone(0.0225, 1, 4, 1);

	glColor3f(1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 0, 0.8f);
	glutSolidCone(0.0325, 0.2, 4, 1);
	//Draw label
	glTranslatef(0, 0.0625, 0.225f);
	RenderSpacedBitmapString(0, 0, 0, GLUT_BITMAP_HELVETICA_10, "X");
	glPopMatrix();
	glutSolidCone(0.0225, 1, 4, 1);

	glColor3f(0, 1, 0);
	glRotatef(90, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 0, 0.8f);
	glutSolidCone(0.0325, 0.2, 4, 1);
	//Draw label
	glTranslatef(0, 0.0625, 0.225f);
	RenderSpacedBitmapString(0, 0, 0, GLUT_BITMAP_HELVETICA_10, "Y");
	glPopMatrix();
	glutSolidCone(0.0225, 1, 4, 1);
	glPopMatrix();
}
void DrawGrid(int GRID_SIZE)
{
	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);
	for (int i = -GRID_SIZE; i <= GRID_SIZE; i++)
	{
		glVertex3f((float)i, 0, (float)-GRID_SIZE);
		glVertex3f((float)i, 0, (float)GRID_SIZE);

		glVertex3f((float)-GRID_SIZE, 0, (float)i);
		glVertex3f((float)GRID_SIZE, 0, (float)i);
	}
	glEnd();
}

//
//
//void StepPhysX()
//{
//	gScene->simulate(myTimestep);
//
//	//...perform useful work here using previous frame's state data        
//	while (!gScene->fetchResults())
//	{
//		// do something useful        
//	}
//}
//
void InitializePhysX() {

	//Recording memory allocations is necessary if you want to 
	//use the memory facilities in PVD effectively.  Since PVD isn't necessarily connected
	//right away, we add a mechanism that records all outstanding memory allocations and
	//forwards them to PVD when it does connect.

	//This certainly has a performance and memory profile effect and thus should be used
	//only in non-production builds.
	bool recordMemoryAllocations = true;
#ifdef RENDERER_ANDROID
	const bool useCustomTrackingAllocator = false;
#else
	const bool useCustomTrackingAllocator = true;
#endif

	PxAllocatorCallback* allocator = &gDefaultAllocatorCallback;

	//if (useCustomTrackingAllocator)
	//	allocator = getSampleAllocator();		//optional override that will track memory allocations

	static PxDefaultErrorCallback gDefaultErrorCallback;
	
	PxFoundation *mFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, *allocator, gDefaultErrorCallback/*getSampleErrorCallback()*/);
	//if (!mFoundation)
	//	fatalError("PxCreateFoundation failed!");

	bool mCreateCudaCtxManager = true;

#if PX_SUPPORT_GPU_PHYSX
	if (mCreateCudaCtxManager)
	{
		PxCudaContextManagerDesc cudaContextManagerDesc;

#if defined(RENDERER_ENABLE_CUDA_INTEROP)
		if (!mApplication.getCommandLine().hasSwitch("nointerop"))
		{
			switch (getRenderer()->getDriverType())
			{
			case Renderer::DRIVER_DIRECT3D11:
				cudaContextManagerDesc.interopMode = PxCudaInteropMode::D3D11_INTEROP;
				break;
			case Renderer::DRIVER_OPENGL:
				cudaContextManagerDesc.interopMode = PxCudaInteropMode::OGL_INTEROP;
				break;
			}
			cudaContextManagerDesc.graphicsDevice = getRenderer()->getDevice();
		}
#endif 
		PxCudaContextManager* mCudaContextManager = PxCreateCudaContextManager(*mFoundation, cudaContextManagerDesc);
		if (mCudaContextManager)
		{
			if (!mCudaContextManager->contextIsValid())
			{
				mCudaContextManager->release();
				mCudaContextManager = NULL;
			}
		}
	}
#endif

	//createPvdConnection();

	PxTolerancesScale scale;
	//customizeTolerances(scale);

	PxPhysics *mPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *mFoundation, scale, recordMemoryAllocations);
	//if (!mPhysics)
	//	fatalError("PxCreatePhysics failed!");

	//if (!PxInitExtensions(*mPhysics, mPvd))
	//	fatalError("PxInitExtensions failed!");

	PxCookingParams params(scale);
	//params.meshWeldTolerance = 0.001f;
	//params.meshPreprocessParams = PxMeshPreprocessingFlags(PxMeshPreprocessingFlag::eWELD_VERTICES);
	//params.buildGPUData = true; //Enable GRB data being produced in cooking.
	PxCooking *mCooking = PxCreateCooking(PX_PHYSICS_VERSION, *mFoundation, params);
	//if (!mCooking)
	//	fatalError("PxCreateCooking failed!");

	//mPhysics->registerDeletionListener(*this, PxDeletionEventFlag::eUSER_RELEASE);

	//// setup default material...
	//mMaterial = mPhysics->createMaterial(0.5f, 0.5f, 0.1f);
	//if (!mMaterial)
	//	fatalError("createMaterial failed!");

#if defined(RENDERER_TABLET)
	// load touchscreen control material
	{
		SampleFramework::SampleAsset* ps_asset = getAsset(controlMaterialPath, SampleFramework::SampleAsset::ASSET_MATERIAL);
		mManagedAssets.push_back(ps_asset);
		PX_ASSERT(ps_asset->getType() == SampleFramework::SampleAsset::ASSET_MATERIAL);
		SampleFramework::SampleMaterialAsset* mat_ps_asset = static_cast<SampleFramework::SampleMaterialAsset*>(ps_asset);
		if (mat_ps_asset->getNumVertexShaders() > 0)
		{
			RenderMaterial* mat = SAMPLE_NEW(RenderMaterial)(*getRenderer(), mat_ps_asset->getMaterial(0), mat_ps_asset->getMaterialInstance(0), MATERIAL_CONTROLS);
			mRenderMaterials.push_back(mat);
		}
	}
	// load touchscreen button material
	{
		SampleFramework::SampleAsset* ps_asset = getAsset(buttonMaterialPath, SampleFramework::SampleAsset::ASSET_MATERIAL);
		mManagedAssets.push_back(ps_asset);
		PX_ASSERT(ps_asset->getType() == SampleFramework::SampleAsset::ASSET_MATERIAL);
		SampleFramework::SampleMaterialAsset* mat_ps_asset = static_cast<SampleFramework::SampleMaterialAsset*>(ps_asset);
		if (mat_ps_asset->getNumVertexShaders() > 0)
		{
			RenderMaterial* mat = SAMPLE_NEW(RenderMaterial)(*getRenderer(), mat_ps_asset->getMaterial(0), mat_ps_asset->getMaterialInstance(0), MATERIAL_BUTTONS);
			mRenderMaterials.push_back(mat);
		}
	}
	Renderer* renderer = getRenderer();
	RenderMaterial* controlMaterial = getMaterial(MATERIAL_CONTROLS);
	renderer->initControls(controlMaterial->mRenderMaterial,
		controlMaterial->mRenderMaterialInstance);
	RenderMaterial* buttonMaterial = getMaterial(MATERIAL_BUTTONS);
	// add buttons for common use
	PxReal yInc = -0.12f;
	PxVec2 leftBottom(0.58f, 0.90f);
	PxVec2 rightTop(0.99f, 0.82f);
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;

	// add buttons for individual sample
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);

	// quick access button
	leftBottom.y += yInc; rightTop.y += yInc;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);

	// next, previous buttons
	leftBottom.x = -0.4f;
	leftBottom.y = 0.9f;
	rightTop.x = -0.1f;
	rightTop.y = 0.82f;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);
	leftBottom.x = 0.1f;
	leftBottom.y = 0.9f;
	rightTop.x = 0.4f;
	rightTop.y = 0.82f;
	renderer->addButton(leftBottom, rightTop, NULL,
		buttonMaterial->mRenderMaterial, buttonMaterial->mRenderMaterialInstance);

#endif		

	PX_ASSERT(NULL == mScene);

	PxSceneDesc sceneDesc(mPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
	//getDefaultSceneDesc(sceneDesc);
	PxDefaultCpuDispatcher*					mCpuDispatcher;


	if (!sceneDesc.cpuDispatcher)
	{
		mCpuDispatcher = PxDefaultCpuDispatcherCreate(1);
		//if (!mCpuDispatcher)
		//	fatalError("PxDefaultCpuDispatcherCreate failed!");
		sceneDesc.cpuDispatcher = mCpuDispatcher;
	}

	if (!sceneDesc.filterShader)
		sceneDesc.filterShader = getSampleFilterShader();

#if PX_SUPPORT_GPU_PHYSX
	if (!sceneDesc.gpuDispatcher && mCudaContextManager)
		sceneDesc.gpuDispatcher = mCudaContextManager->getGpuDispatcher();
#endif

	//sceneDesc.frictionType = PxFrictionType::eTWO_DIRECTIONAL;
	//sceneDesc.frictionType = PxFrictionType::eONE_DIRECTIONAL;
	sceneDesc.flags |= PxSceneFlag::eENABLE_GPU_DYNAMICS;
	sceneDesc.flags |= PxSceneFlag::eENABLE_PCM;
	//sceneDesc.flags |= PxSceneFlag::eENABLE_AVERAGE_POINT;
	sceneDesc.flags |= PxSceneFlag::eENABLE_STABILIZATION;
	//sceneDesc.flags |= PxSceneFlag::eADAPTIVE_FORCE;
	sceneDesc.flags |= PxSceneFlag::eENABLE_ACTIVETRANSFORMS;
	sceneDesc.flags |= PxSceneFlag::eSUPPRESS_EAGER_SCENE_QUERY_REFIT;
	//sceneDesc.flags |= PxSceneFlag::eDISABLE_CONTACT_CACHE;
	sceneDesc.broadPhaseType = PxBroadPhaseType::eGPU;
	sceneDesc.gpuMaxNumPartitions = 8;


#ifdef USE_MBP
	sceneDesc.broadPhaseType = PxBroadPhaseType::eMBP;
#endif

	customizeSceneDesc(sceneDesc);

	mScene = mPhysics->createScene(sceneDesc);
	if (!mScene)
		fatalError("createScene failed!");

	PxSceneWriteLock scopedLock(*mScene);

	PxSceneFlags flag = mScene->getFlags();

	PX_UNUSED(flag);
	mScene->setVisualizationParameter(PxVisualizationParameter::eSCALE, mInitialDebugRender ? mDebugRenderScale : 0.0f);
	mScene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);

	PxPvdSceneClient* pvdClient = mScene->getScenePvdClient();
	if (pvdClient)
	{
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);
	}

#ifdef USE_MBP
	setupMBP(*mScene);
#endif

	mApplication.refreshVisualizationMenuState(PxVisualizationParameter::eCOLLISION_SHAPES);
	mApplication.applyDefaultVisualizationSettings();
	mApplication.setMouseCursorHiding(false);
	mApplication.setMouseCursorRecentering(false);
	mCameraController.setMouseLookOnMouseButton(false);
	mCameraController.setMouseSensitivity(1.0f);

	if (mCreateGroundPlane)
		createGrid();

	LOG_INFO("PhysXSample", "Init sample ok!");
}
//	gPhysicsSDK = PxCreatePhysics(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback, PxTolerancesScale());
//	if (gPhysicsSDK == NULL) {
//		cerr << "Error creating PhysX3 device." << endl;
//		cerr << "Exiting..." << endl;
//		exit(1);
//	}
//
//	if (!PxInitExtensions(*gPhysicsSDK))
//		cerr << "PxInitExtensions failed!" << endl;
//
//	//PxExtensionVisualDebugger::connect(gPhysicsSDK->getPvdConnectionManager(),"localhost",5425, 10000, true);
//
//
//	//Create the scene
//	PxSceneDesc sceneDesc(gPhysicsSDK->getTolerancesScale());
//	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
//
//	if (!sceneDesc.cpuDispatcher) {
//		PxDefaultCpuDispatcher* mCpuDispatcher = PxDefaultCpuDispatcherCreate(1);
//		if (!mCpuDispatcher)
//			cerr << "PxDefaultCpuDispatcherCreate failed!" << endl;
//		sceneDesc.cpuDispatcher = mCpuDispatcher;
//	}
//	if (!sceneDesc.filterShader)
//		sceneDesc.filterShader = gDefaultFilterShader;
//
//
//	gScene = gPhysicsSDK->createScene(sceneDesc);
//	if (!gScene)
//		cerr << "createScene failed!" << endl;
//
//	gScene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0);
//	gScene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
//
//
//	PxMaterial* mMaterial = gPhysicsSDK->createMaterial(0.5, 0.5, 0.5);
//
//	//Create actors 
//	//1) Create ground plane
//	PxReal d = 0.0f;
//	PxTransform pose = PxTransform(PxVec3(0.0f, 0, 0.0f), PxQuat(PxHalfPi, PxVec3(0.0f, 0.0f, 1.0f)));
//
//	PxRigidStatic* plane = gPhysicsSDK->createRigidStatic(pose);
//	if (!plane)
//		cerr << "create plane failed!" << endl;
//
//	PxShape* shape = plane->createShape(PxPlaneGeometry(), *mMaterial);
//	if (!shape)
//		cerr << "create shape failed!" << endl;
//	gScene->addActor(*plane);
//
//
//	//2) Create cube	 
//	PxReal density = 1.0f;
//	PxTransform transform(PxVec3(0.0f, 10.0f, 0.0f), PxQuat::createIdentity());
//	PxVec3 dimensions(0.5, 0.5, 0.5);
//	PxBoxGeometry geometry(dimensions);
//
//	PxRigidDynamic *actor = PxCreateDynamic(*gPhysicsSDK, transform, geometry, *mMaterial, density);
//	actor->setAngularDamping(0.75);
//	actor->setLinearVelocity(PxVec3(0, 0, 0));
//	if (!actor)
//		cerr << "create actor failed!" << endl;
//	gScene->addActor(*actor);
//
//	box = actor;
//}
//
//void getColumnMajor(PxMat33 m, PxVec3 t, float* mat) {
//	mat[0] = m.column0[0];
//	mat[1] = m.column0[1];
//	mat[2] = m.column0[2];
//	mat[3] = 0;
//
//	mat[4] = m.column1[0];
//	mat[5] = m.column1[1];
//	mat[6] = m.column1[2];
//	mat[7] = 0;
//
//	mat[8] = m.column2[0];
//	mat[9] = m.column2[1];
//	mat[10] = m.column2[2];
//	mat[11] = 0;
//
//	mat[12] = t[0];
//	mat[13] = t[1];
//	mat[14] = t[2];
//	mat[15] = 1;
//}
//
//void DrawBox(PxShape* pShape) {
//	PxTransform pT = PxShapeExt::getGlobalPose(*pShape);
//	PxBoxGeometry bg;
//	pShape->getBoxGeometry(bg);
//	PxMat33 m = PxMat33Legacy(pT.q);
//	float mat[16];
//	getColumnMajor(m, pT.p, mat);
//	glPushMatrix();
//	glMultMatrixf(mat);
//	glutSolidCube(bg.halfExtents.x * 2);
//	glPopMatrix();
//}
//
//void DrawShape(PxShape* shape)
//{
//	PxGeometryType::Enum type = shape->getGeometryType();
//	switch (type)
//	{
//	case PxGeometryType::eBOX:
//		DrawBox(shape);
//		break;
//	}
//}
//
//void DrawActor(PxRigidActor* actor)
//{
//	PxU32 nShapes = actor->getNbShapes();
//	PxShape** shapes = new PxShape*[nShapes];
//
//	actor->getShapes(shapes, nShapes);
//	while (nShapes--)
//	{
//		DrawShape(shapes[nShapes]);
//	}
//	delete[] shapes;
//}

//void RenderActors()
//{
//	// Render all the actors in the scene 
//
//	DrawActor(box);
//}



//
//void ShutdownPhysX() {
//	gScene->removeActor(*box);
//	gScene->release();
//	box->release();
//	gPhysicsSDK->release();
//}

void InitGL() {
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat ambient[4] = { 0.25f,0.25f,0.25f,0.25f };
	GLfloat diffuse[4] = { 1,1,1,1 };
	GLfloat mat_diffuse[4] = { 0.85f,0,0,0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);

	glDisable(GL_LIGHTING);
}

void OnReshape(int nw, int nh) {
	glViewport(0, 0, nw, nh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)nw / (GLfloat)nh, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

char buffer[MAX_PATH];
void OnRender() {
	//Calculate fps
	totalFrames++;
	int current = glutGet(GLUT_ELAPSED_TIME);
	if ((current - startTime)>1000)
	{
		float elapsedTime = float(current - startTime);
		fps = ((totalFrames * 1000.0f) / elapsedTime);
		startTime = current;
		totalFrames = 0;
	}

	sprintf_s(buffer, "FPS: %3.2f", fps);

	//Update PhysX	
	//if (gScene)
	//{
	//	StepPhysX();
	//}


	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, dist);
	glRotatef(rX, 1, 0, 0);
	glRotatef(rY, 0, 1, 0);

	//Draw the grid and axes
	DrawAxes();
	DrawGrid(10);

	glEnable(GL_LIGHTING);
	//RenderActors();
	glDisable(GL_LIGHTING);

	SetOrthoForFont();
	glColor3f(1, 1, 1);
	//Show the fps
	RenderSpacedBitmapString(20, 20, 0, GLUT_BITMAP_HELVETICA_12, buffer);

	ResetPerspectiveProjection();

	glutSwapBuffers();
}

void OnShutdown() {
	//ShutdownPhysX();
}


void Mouse(int button, int s, int x, int y)
{
	if (s == GLUT_DOWN)
	{
		oldX = x;
		oldY = y;
	}

	if (button == GLUT_MIDDLE_BUTTON)
		state = 0;
	else
		state = 1;
}

void Motion(int x, int y)
{
	if (state == 0)
		dist *= (1 + (y - oldY) / 60.0f);
	else
	{
		rY += (x - oldX) / 5.0f;
		rX += (y - oldY) / 5.0f;
	}
	oldX = x;
	oldY = y;

	glutPostRedisplay();
}

void OnIdle() {
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	atexit(OnShutdown);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("GLUT PhysX3 Demo - Simple Box");

	glutDisplayFunc(OnRender);
	glutIdleFunc(OnIdle);
	glutReshapeFunc(OnReshape);

	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	InitGL();
	//InitializePhysX();

	glutMainLoop();

    return 0;
}

