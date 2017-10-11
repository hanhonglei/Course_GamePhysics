// GlutPhysX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Physics.h"
#include "Graphics.h"

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

/*Global parameters*/
const int	WINDOW_WIDTH = 1024,
WINDOW_HEIGHT = 768;

int oldX = 0, oldY = 0;
float rX = 15, rY = 0;
float fps = 0;
int startTime = 0;
int totalFrames = 0;
int state = 1;
float dist = -5;
char buffer[MAX_PATH];
bool shoot = false;

// Release physics resources
void OnShutdown() {
	ShutdownPhysX();
}
// mouse movement
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

	//if (s == GLUT_UP|GLUT_LEFT_BUTTON)
	//{
	//	shoot = true;
	//	glutPostRedisplay();
	//}

}
// camera adjust
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
// idle function to repaint
void OnIdle() {
	glutPostRedisplay();
}
// main render function called by glut
void OnRender() {
	//Calculate fps
	totalFrames++;
	int current = glutGet(GLUT_ELAPSED_TIME);
	float elapsedTime = float(current - startTime);
	static float lastfpsTime = 0.0f;
	if ((current - lastfpsTime) > 1000.0f)
	{
		fps = ((totalFrames * 1000.0f) / ((current - lastfpsTime)));
		totalFrames = 0;
		lastfpsTime = float(current);
	}
	startTime = current;

	sprintf_s(buffer, "FPS: %3.2f", fps);

	//Update PhysX	
	if (gScene)
	{
		stepPhysics(elapsedTime / 1000.0f);
	}

	// start render
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0, 0, dist);
	glRotatef(rX, 1, 0, 0);
	glRotatef(rY, 0, 1, 0);
	// shoot
	if (shoot)
	{
		GLdouble matModelView[16], matProjection[16];
		GLdouble camera_pos[3];
		int viewport[4];
		// get matrixs and viewport:
		glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
		glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		gluUnProject((viewport[2] - viewport[0]) / 2, (viewport[3] - viewport[1]) / 2,
			0.0, matModelView, matProjection, viewport,
			&camera_pos[0], &camera_pos[1], &camera_pos[2]);

		//PxVec3 p(camera_pos[0], camera_pos[1], camera_pos[2]);
		//AddBullet(p, -p.getNormalized() * 10.0f);
		shoot = false;

		//
		//GLdouble mpos[3];
		//gluUnProject(oldX, oldY, 0,
		//	matModelView,
		//	matProjection, viewport, &mpos[0], &mpos[1], &mpos[2]);
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		winX = (float)(viewport[2] - viewport[0]) / 2;
		winY = (float)(viewport[3] - viewport[1]) / 2;
		glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);


		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, 0.0, matModelView, matProjection
			, viewport, &worldX, &worldY, &worldZ);
		GLdouble fx, fy, fz;
		gluUnProject(winX, winY, 1.0, matModelView, matProjection
			, viewport, &fx, &fy, &fz);

		PxVec3 pp(worldX, worldY, worldZ);
		PxVec3 vv(fx - worldX, fy - worldY, fz - worldZ);
		AddBullet(pp, vv.getNormalized() * 10.0f);
	}
	//Draw the grid and axes
	DrawAxes();
	DrawGrid(100);
	// draw physics objects
	glEnable(GL_LIGHTING);
	RenderPhysXScene();
	glDisable(GL_LIGHTING);

	//Show the fps
	SetOrthoForFont(WINDOW_WIDTH, WINDOW_HEIGHT);
	glColor3f(1, 1, 1);
	RenderSpacedBitmapString(20, 20, 0, GLUT_BITMAP_HELVETICA_12, buffer);

	ResetPerspectiveProjection();
	// finish render
	glutSwapBuffers();
}
void Keyboard(unsigned char key, int x, int y)
{
	if (key == 32)
	{
		shoot = true;
		glutPostRedisplay();
	}
		printf("%uc", key);
}
// main function, register functions to glut routine
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
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(Motion);
	InitGL();
	InitializePhysX();

	glutMainLoop();

	return 0;
}

