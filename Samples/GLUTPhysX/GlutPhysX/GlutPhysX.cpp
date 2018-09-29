// ʹ��Glut����PhysX�����demo
// ֻʹ�����Ҫ�Ĺ���
// ����glut���д������ã��Լ��û�����
// Ҫ������Ⱦ�˺�������������Ƥԭ��
// ��Ⱦ���������״�ͱ任����ͨ����������õ��ģ���Ⱦ��ֻ�Ǳ�������

#include "stdafx.h"
#include "Physics.h"
#include "Graphics.h"

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
	glutMotionFunc(Motion);
	InitGL();
	InitializePhysX();

	glutMainLoop();

	return 0;
}

