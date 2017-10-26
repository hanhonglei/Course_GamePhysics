#include "stdafx.h"
#include "Graphics.h"

#define MAX_NUM_MESH_VEC3S  1024
static PxVec3 gVertexBuffer[MAX_NUM_MESH_VEC3S];

static float gCylinderData[] = {
	1.0f,0.0f,1.0f,1.0f,0.0f,1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,
	0.866025f,0.500000f,1.0f,0.866025f,0.500000f,1.0f,0.866025f,0.500000f,0.0f,0.866025f,0.500000f,0.0f,
	0.500000f,0.866025f,1.0f,0.500000f,0.866025f,1.0f,0.500000f,0.866025f,0.0f,0.500000f,0.866025f,0.0f,
	-0.0f,1.0f,1.0f,-0.0f,1.0f,1.0f,-0.0f,1.0f,0.0f,-0.0f,1.0f,0.0f,
	-0.500000f,0.866025f,1.0f,-0.500000f,0.866025f,1.0f,-0.500000f,0.866025f,0.0f,-0.500000f,0.866025f,0.0f,
	-0.866025f,0.500000f,1.0f,-0.866025f,0.500000f,1.0f,-0.866025f,0.500000f,0.0f,-0.866025f,0.500000f,0.0f,
	-1.0f,-0.0f,1.0f,-1.0f,-0.0f,1.0f,-1.0f,-0.0f,0.0f,-1.0f,-0.0f,0.0f,
	-0.866025f,-0.500000f,1.0f,-0.866025f,-0.500000f,1.0f,-0.866025f,-0.500000f,0.0f,-0.866025f,-0.500000f,0.0f,
	-0.500000f,-0.866025f,1.0f,-0.500000f,-0.866025f,1.0f,-0.500000f,-0.866025f,0.0f,-0.500000f,-0.866025f,0.0f,
	0.0f,-1.0f,1.0f,0.0f,-1.0f,1.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,
	0.500000f,-0.866025f,1.0f,0.500000f,-0.866025f,1.0f,0.500000f,-0.866025f,0.0f,0.500000f,-0.866025f,0.0f,
	0.866026f,-0.500000f,1.0f,0.866026f,-0.500000f,1.0f,0.866026f,-0.500000f,0.0f,0.866026f,-0.500000f,0.0f,
	1.0f,0.0f,1.0f,1.0f,0.0f,1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f
};

// Render font
void SetOrthoForFont(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, GLfloat(-h), 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// reset project view
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

void renderGeometry(const PxGeometryHolder& h)
{
	switch (h.getType())
	{
	case PxGeometryType::eBOX:
	{
		glScalef(h.box().halfExtents.x, h.box().halfExtents.y, h.box().halfExtents.z);
		glutSolidCube(2.0);

	}
	break;
	case PxGeometryType::eSPHERE:
	{
		glutSolidSphere(GLdouble(h.sphere().radius), 100, 100);
	}
	break;
	case PxGeometryType::eCAPSULE:
	{

		const PxF32 radius = h.capsule().radius;
		const PxF32 halfHeight = h.capsule().halfHeight;

		//Sphere
		glPushMatrix();
		glTranslatef(halfHeight, 0.0f, 0.0f);
		glScalef(radius, radius, radius);
		glutSolidSphere(1, 10, 10);
		glPopMatrix();

		//Sphere
		glPushMatrix();
		glTranslatef(-halfHeight, 0.0f, 0.0f);
		glScalef(radius, radius, radius);
		glutSolidSphere(1, 10, 10);
		glPopMatrix();

		//Cylinder
		glPushMatrix();
		glTranslatef(-halfHeight, 0.0f, 0.0f);
		glScalef(2.0f*halfHeight, radius, radius);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 2 * 3 * sizeof(float), gCylinderData);
		glNormalPointer(GL_FLOAT, 2 * 3 * sizeof(float), gCylinderData + 3);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 13 * 2);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glPopMatrix();
	}
	break;
	case PxGeometryType::eCONVEXMESH:
	{

		//Compute triangles for each polygon.
		const PxVec3 scale = h.convexMesh().scale.scale;
		PxConvexMesh* mesh = h.convexMesh().convexMesh;
		const PxU32 nbPolys = mesh->getNbPolygons();
		const PxU8* polygons = mesh->getIndexBuffer();
		const PxVec3* verts = mesh->getVertices();
		PxU32 nbVerts = mesh->getNbVertices();
		PX_UNUSED(nbVerts);

		PxU32 numTotalTriangles = 0;
		for (PxU32 i = 0; i < nbPolys; i++)
		{
			PxHullPolygon data;
			mesh->getPolygonData(i, data);

			const PxU32 nbTris = PxU32(data.mNbVerts - 2);
			const PxU8 vref0 = polygons[data.mIndexBase + 0];
			PX_ASSERT(vref0 < nbVerts);
			for (PxU32 j = 0; j < nbTris; j++)
			{
				const PxU32 vref1 = polygons[data.mIndexBase + 0 + j + 1];
				const PxU32 vref2 = polygons[data.mIndexBase + 0 + j + 2];

				//generate face normal:
				PxVec3 e0 = verts[vref1] - verts[vref0];
				PxVec3 e1 = verts[vref2] - verts[vref0];

				PX_ASSERT(vref1 < nbVerts);
				PX_ASSERT(vref2 < nbVerts);

				PxVec3 fnormal = e0.cross(e1);
				fnormal.normalize();

				if (numTotalTriangles * 6 < MAX_NUM_MESH_VEC3S)
				{
					gVertexBuffer[numTotalTriangles * 6 + 0] = fnormal;
					gVertexBuffer[numTotalTriangles * 6 + 1] = verts[vref0];
					gVertexBuffer[numTotalTriangles * 6 + 2] = fnormal;
					gVertexBuffer[numTotalTriangles * 6 + 3] = verts[vref1];
					gVertexBuffer[numTotalTriangles * 6 + 4] = fnormal;
					gVertexBuffer[numTotalTriangles * 6 + 5] = verts[vref2];
					numTotalTriangles++;
				}
			}
		}
		glPushMatrix();
		glScalef(scale.x, scale.y, scale.z);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glNormalPointer(GL_FLOAT, 2 * 3 * sizeof(float), gVertexBuffer);
		glVertexPointer(3, GL_FLOAT, 2 * 3 * sizeof(float), gVertexBuffer + 1);
		glDrawArrays(GL_TRIANGLES, 0, int(numTotalTriangles * 3));
		glPopMatrix();
	}
	break;
	case PxGeometryType::eTRIANGLEMESH:
	{
		const PxTriangleMeshGeometry& triGeom = h.triangleMesh();
		const PxTriangleMesh& mesh = *triGeom.triangleMesh;
		const PxVec3 scale = triGeom.scale.scale;

		const PxU32 triangleCount = mesh.getNbTriangles();
		const PxU32 has16BitIndices = mesh.getTriangleMeshFlags() & PxTriangleMeshFlag::e16_BIT_INDICES;
		const void* indexBuffer = mesh.getTriangles();

		const PxVec3* vertexBuffer = mesh.getVertices();

		const PxU32* intIndices = reinterpret_cast<const PxU32*>(indexBuffer);
		const PxU16* shortIndices = reinterpret_cast<const PxU16*>(indexBuffer);
		PxU32 numTotalTriangles = 0;
		for (PxU32 i = 0; i < triangleCount; ++i)
		{
			PxVec3 triVert[3];

			if (has16BitIndices)
			{
				triVert[0] = vertexBuffer[*shortIndices++];
				triVert[1] = vertexBuffer[*shortIndices++];
				triVert[2] = vertexBuffer[*shortIndices++];
			}
			else
			{
				triVert[0] = vertexBuffer[*intIndices++];
				triVert[1] = vertexBuffer[*intIndices++];
				triVert[2] = vertexBuffer[*intIndices++];
			}

			PxVec3 fnormal = (triVert[1] - triVert[0]).cross(triVert[2] - triVert[0]);
			fnormal.normalize();

			if (numTotalTriangles * 6 < MAX_NUM_MESH_VEC3S)
			{
				gVertexBuffer[numTotalTriangles * 6 + 0] = fnormal;
				gVertexBuffer[numTotalTriangles * 6 + 1] = triVert[0];
				gVertexBuffer[numTotalTriangles * 6 + 2] = fnormal;
				gVertexBuffer[numTotalTriangles * 6 + 3] = triVert[1];
				gVertexBuffer[numTotalTriangles * 6 + 4] = fnormal;
				gVertexBuffer[numTotalTriangles * 6 + 5] = triVert[2];
				numTotalTriangles++;
			}
		}
		glPushMatrix();
		glScalef(scale.x, scale.y, scale.z);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glNormalPointer(GL_FLOAT, 2 * 3 * sizeof(float), gVertexBuffer);
		glVertexPointer(3, GL_FLOAT, 2 * 3 * sizeof(float), gVertexBuffer + 1);
		glDrawArrays(GL_TRIANGLES, 0, int(numTotalTriangles * 3));
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glPopMatrix();
	}
	break;
	case PxGeometryType::eINVALID:
	case PxGeometryType::eHEIGHTFIELD:
	case PxGeometryType::eGEOMETRY_COUNT:
	case PxGeometryType::ePLANE:
		break;
	}
}

void setupDefaultRenderState()
{
	// Setup default render states
	glClearColor(0.3f, 0.4f, 0.5f, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	// Setup lighting
	glEnable(GL_LIGHTING);
	PxReal ambientColor[] = { 0.0f, 0.1f, 0.2f, 0.0f };
	PxReal diffuseColor[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	PxReal specularColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	PxReal position[] = { 100.0f, 100.0f, 400.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularColor);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
}
// render physics actors based on their gestures
void renderActors(PxRigidActor** actors, const PxU32 numActors, bool shadows, const PxVec3 & color)
{
	PxShape* shapes[1024];
	for (PxU32 i = 0; i < numActors; i++)
	{
		const PxU32 nbShapes = actors[i]->getNbShapes();
		PX_ASSERT(nbShapes <= MAX_NUM_ACTOR_SHAPES);
		actors[i]->getShapes(shapes, nbShapes);
		bool sleeping = actors[i]->is<PxRigidDynamic>() ? actors[i]->is<PxRigidDynamic>()->isSleeping() : false;

		for (PxU32 j = 0; j < nbShapes; j++)
		{
			const PxMat44 shapePose(PxShapeExt::getGlobalPose(*shapes[j], *actors[i]));
			PxGeometryHolder h = shapes[j]->getGeometry();

			if (shapes[j]->getFlags() & PxShapeFlag::eTRIGGER_SHAPE)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			// render object
			glPushMatrix();
			glMultMatrixf(reinterpret_cast<const float*>(&shapePose));
			if (sleeping)
			{
				PxVec3 darkColor = color * 0.25f;
				glColor4f(darkColor.x, darkColor.y, darkColor.z, 1.0f);
			}
			else
				glColor4f(color.x, color.y, color.z, 1.0f);
			renderGeometry(h);
			glPopMatrix();

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			if (shadows)
			{
				const PxVec3 shadowDir(0.0f, -0.7071067f, -0.7071067f);
				const PxReal shadowMat[] = { 1,0,0,0, -shadowDir.x / shadowDir.y,0,-shadowDir.z / shadowDir.y,0, 0,0,1,0, 0,0,0,1 };
				glPushMatrix();
				glMultMatrixf(shadowMat);
				glMultMatrixf(reinterpret_cast<const float*>(&shapePose));
				glDisable(GL_LIGHTING);
				glColor4f(0.1f, 0.2f, 0.3f, 1.0f);
				renderGeometry(h);
				glEnable(GL_LIGHTING);
				glPopMatrix();
			}
		}
	}
}
// render all object in PhysX scene
void RenderPhysXScene()
{
	// Render all the actors in the scene 
	PxScene* scene;
	PxGetPhysics().getScenes(&scene, 1);
	PxU32 nbActors = scene->getNbActors(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC);
	if (nbActors)
	{
		std::vector<PxRigidActor*> actors(nbActors);
		scene->getActors(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC, reinterpret_cast<PxActor**>(&actors[0]), nbActors);
		renderActors(&actors[0], static_cast<PxU32>(actors.size()));
	}
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	const PxRenderBuffer& rb = scene->getRenderBuffer();
	glBegin(GL_LINES);
	for (PxU32 i = 0; i < rb.getNbLines(); i++)
	{
		const PxDebugLine& line = rb.getLines()[i];
		// render the line
		glVertex3f(line.pos0.x, line.pos0.y, line.pos0.z);
		glVertex3f(line.pos1.x, line.pos1.y, line.pos1.z);
	}
	glEnd();
}
// initialize OpenGL
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

	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}
// resize window
void OnReshape(int nw, int nh) {
	glViewport(0, 0, nw, nh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)nw / (GLfloat)nh, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}


