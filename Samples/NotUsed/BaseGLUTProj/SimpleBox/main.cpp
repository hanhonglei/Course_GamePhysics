#include <iostream>
#include <GL/freeglut.h>
#include <PxPhysicsAPI.h> 
//#include <PxExtensionsAPI.h> 
//#include <PxDefaultErrorCallback.h>
//#include <PxDefaultAllocator.h> 
//#include <PxDefaultSimulationFilterShader.h>
//#include <PxDefaultCpuDispatcher.h>
//#include <PxShapeExt.h>
//#include <PxMat33Legacy.h> 
//#include <PxSimpleFactory.h>

using namespace std;
using namespace physx;

#pragma comment(lib, "PhysX3DEBUG_X86.lib")
#pragma comment(lib, "PhysX3CommonDEBUG_X86.lib")
#pragma comment(lib, "PxFoundationDEBUG_X86.lib")
#pragma comment(lib, "PhysX3ExtensionsDEBUG.lib")
#pragma comment(lib, "PxPvdSDKDEBUG_x86.lib")

const int	WINDOW_WIDTH=1024, 
WINDOW_HEIGHT=768;

/*Global PhyX related parameters*/
PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;
PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics = NULL;
PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene = NULL;
PxMaterial*				gMaterial = NULL;
PxPvd*                  gPvd = NULL;

PxReal myTimestep = 1.0f/60.0f;
PxRigidActor *box;


//for mouse dragging
int oldX=0, oldY=0;
float rX=15, rY=0;
float fps=0;
int startTime=0;
int totalFrames=0;
int state =1 ;
float dist=-5;

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
	int x1=x;
	for (c=string; *c != '\0'; c++) {
		glRasterPos2i(x1,y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font,*c) + spacing;
	}
}


void DrawAxes()
{	 
	//To prevent the view from disturbed on repaint
	//this push matrix call stores the current matrix state
	//and restores it once we are done with the arrow rendering
	glPushMatrix();
		glColor3f(0,0,1);
		glPushMatrix();
			glTranslatef(0,0, 0.8f);
			glutSolidCone(0.0325,0.2, 4,1);
			//Draw label			
			glTranslatef(0,0.0625,0.225f);
			RenderSpacedBitmapString(0,0,0,GLUT_BITMAP_HELVETICA_10, "Z");
		glPopMatrix();					
		glutSolidCone(0.0225,1, 4,1);

		glColor3f(1,0,0);
		glRotatef(90,0,1,0);	
		glPushMatrix();
			glTranslatef(0,0,0.8f);
			glutSolidCone(0.0325,0.2, 4,1);
			//Draw label
			glTranslatef(0,0.0625,0.225f);
			RenderSpacedBitmapString(0,0,0,GLUT_BITMAP_HELVETICA_10, "X");
		glPopMatrix();					
		glutSolidCone(0.0225,1, 4,1);

		glColor3f(0,1,0);
		glRotatef(90,-1,0,0);	
		glPushMatrix();
			glTranslatef(0,0, 0.8f);
			glutSolidCone(0.0325,0.2, 4,1);
			//Draw label
			glTranslatef(0,0.0625,0.225f);
			RenderSpacedBitmapString(0,0,0,GLUT_BITMAP_HELVETICA_10, "Y");
		glPopMatrix();					
		glutSolidCone(0.0225,1, 4,1);	
	glPopMatrix();
}
void DrawGrid(int GRID_SIZE)
{
	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);
	for(int i=-GRID_SIZE;i<=GRID_SIZE;i++)
	{
		glVertex3f((float)i,0,(float)-GRID_SIZE);
		glVertex3f((float)i,0,(float)GRID_SIZE);

		glVertex3f((float)-GRID_SIZE,0,(float)i);
		glVertex3f((float)GRID_SIZE,0,(float)i);
	}
	glEnd();
}



void StepPhysX() 
{ 
	gScene->simulate(myTimestep);        
	       
	//...perform useful work here using previous frame's state data        
	while(!gScene->fetchResults() )     
	{
		// do something useful        
	}
} 

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
	sceneDesc.filterShader = PxDefaultSimulationFilterShader;
	gScene = gPhysics->createScene(sceneDesc);

	PxPvdSceneClient* pvdClient = gScene->getScenePvdClient();
	if (pvdClient)
	{
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
		pvdClient->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);
	}
	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);
	 
	//Create actors 
    //1) Create ground plane
    PxReal d = 0.0f;	 
	PxTransform pose = PxTransform(PxVec3(0.0f, 0, 0.0f),PxQuat(PxHalfPi, PxVec3(0.0f, 0.0f, 1.0f)));

	PxRigidStatic* plane = gPhysics->createRigidStatic(pose);
	if (!plane)
			cerr<<"create plane failed!"<<endl;

	PxShape* shape = plane->createShape(PxPlaneGeometry(), *gMaterial);
	if (!shape)
		cerr<<"create shape failed!"<<endl;
	gScene->addActor(*plane);


	//2) Create cube	 
	PxReal density = 1.0f;
	PxTransform transform(PxVec3(0.0f, 10.0f, 0.0f));
	PxVec3 dimensions(0.5,0.5,0.5);
	PxBoxGeometry geometry(dimensions);
    
	PxRigidDynamic *actor = PxCreateDynamic(*gPhysics, transform, geometry, *gMaterial, density);
    actor->setAngularDamping(0.75);
    actor->setLinearVelocity(PxVec3(0,0,0)); 
	if (!actor)
		cerr<<"create actor failed!"<<endl;
	gScene->addActor(*actor);

	box = actor;
}
 
void getColumnMajor(PxMat33 m, PxVec3 t, float* mat) {
   mat[0] = m.column0[0];
   mat[1] = m.column0[1];
   mat[2] = m.column0[2];
   mat[3] = 0;

   mat[4] = m.column1[0];
   mat[5] = m.column1[1];
   mat[6] = m.column1[2];
   mat[7] = 0;

   mat[8] = m.column2[0];
   mat[9] = m.column2[1];
   mat[10] = m.column2[2];
   mat[11] = 0;

   mat[12] = t[0];
   mat[13] = t[1];
   mat[14] = t[2];
   mat[15] = 1;
}
 
void DrawBox(PxShape* pShape) {
	const PxMat44 shapePose(PxShapeExt::getGlobalPose(*pShape, *pShape->getActor()));
	PxBoxGeometry bg;
	pShape->getBoxGeometry(bg);
	glPushMatrix(); 
		//glMultMatrixf(mat);
	glMultMatrixf(reinterpret_cast<const float*>(&shapePose));

		glutSolidCube(bg.halfExtents.x*2);
    glPopMatrix(); 
}
void DrawShape(PxShape* shape) 
{ 
	PxGeometryType::Enum type = shape->getGeometryType();
    switch(type) 
    {          
		case PxGeometryType::eBOX:
			DrawBox(shape);
		break;
    } 
} 

void DrawActor(PxRigidActor* actor) 
{  
	PxU32 nShapes = actor->getNbShapes(); 
    PxShape** shapes=new PxShape*[nShapes];
	
	actor->getShapes(shapes, nShapes);     
    while (nShapes--) 
    { 
        DrawShape(shapes[nShapes]); 
    } 
	delete [] shapes;
} 

void RenderActors() 
{ 
    // Render all the actors in the scene 
	 
	DrawActor(box);
} 
 



void ShutdownPhysX() {
	gScene->removeActor(*box);	
	gScene->release();
	box->release();
	gPhysics->release();
}

void InitGL() { 
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat ambient[4]={0.25f,0.25f,0.25f,0.25f};
	GLfloat diffuse[4]={1,1,1,1};
	GLfloat mat_diffuse[4]={0.85f,0,0,0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);

	glDisable(GL_LIGHTING);
}

void OnReshape(int nw, int nh) {
	glViewport(0,0,nw, nh);
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
	if((current-startTime)>1000)
	{		
		float elapsedTime = float(current-startTime);
		fps = ((totalFrames * 1000.0f)/ elapsedTime) ;
		startTime = current;
		totalFrames=0;
	}

	sprintf_s(buffer, "FPS: %3.2f",fps);

	//Update PhysX	
    if (gScene) 
    { 
        StepPhysX(); 
    } 


	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0,dist);
	glRotatef(rX,1,0,0);
	glRotatef(rY,0,1,0);

	//Draw the grid and axes
	DrawAxes();	
	DrawGrid(10);
	
	glEnable(GL_LIGHTING);
		RenderActors();
	glDisable(GL_LIGHTING);

	SetOrthoForFont();		
		glColor3f(1,1,1);
		//Show the fps
		RenderSpacedBitmapString(20,20,0,GLUT_BITMAP_HELVETICA_12,buffer);

	ResetPerspectiveProjection();

	glutSwapBuffers();
}

void OnShutdown() {
	ShutdownPhysX();
}


void Mouse(int button, int s, int x, int y)
{
	if (s == GLUT_DOWN) 
	{
		oldX = x; 
		oldY = y; 
	}	
	
	if(button == GLUT_MIDDLE_BUTTON)
		state = 0;
	else
		state = 1;
}

void Motion(int x, int y)
{
	if (state == 0)
		dist *= (1 + (y - oldY)/60.0f); 
	else
	{
		rY += (x - oldX)/5.0f; 
		rX += (y - oldY)/5.0f; 
	} 
	oldX = x; 
	oldY = y; 
	 
	glutPostRedisplay(); 
}

void OnIdle() {
	glutPostRedisplay();
}

void main(int argc, char** argv) {
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
	InitializePhysX();

	glutMainLoop();		
}
