#pragma once
#include "stdafx.h"

extern PxScene*				gScene;

// Set up PhysX
void InitializePhysX();

void ShutdownPhysX();

void stepPhysics(PxReal timeStep);
void AddBullet(const PxVec3& pos, const PxVec3& v);