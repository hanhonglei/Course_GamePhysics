#pragma once
#include "stdafx.h"

// Render font
void SetOrthoForFont(int w, int h);

void ResetPerspectiveProjection();
void RenderSpacedBitmapString(
	int x,
	int y,
	int spacing,
	void *font,
	char *string);

void DrawAxes();

void DrawGrid(int GRID_SIZE);

void renderGeometry(const PxGeometryHolder& h, bool isShadow = false);


void setupDefaultRenderState();


void renderActors(physx::PxRigidActor** actors, const physx::PxU32 numActors, bool shadows = false, const physx::PxVec3 & color = physx::PxVec3(0.0f, 0.75f, 0.0f));

void RenderPhysXScene();


void InitGL();

void OnReshape(int nw, int nh);

void OnRender();