#pragma once
#include "stdafx.h"

extern PxScene*				gScene;

// Set up PhysX
void InitializePhysX();

void ShutdownPhysX();

void stepPhysics(PxReal timeStep);