#pragma once
#include "stdafx.h"

extern PxScene*				gScene;

// Set up PhysX
void InitializePhysX();

void ShutdownPhysX();

void stepPhysics(PxReal timeStep);
void AddBullet(const PxVec3& pos, const PxVec3& v);
void MoveCharacter(unsigned char key);


struct VehicleDesc
{
	VehicleDesc()
		: chassisMass(0.0f),
		chassisDims(PxVec3(0.0f, 0.0f, 0.0f)),
		chassisMOI(PxVec3(0.0f, 0.0f, 0.0f)),
		chassisCMOffset(PxVec3(0.0f, 0.0f, 0.0f)),
		chassisMaterial(NULL),
		wheelMass(0.0f),
		wheelWidth(0.0f),
		wheelRadius(0.0f),
		wheelMOI(0.0f),
		wheelMaterial(NULL),
		actorUserData(NULL),
		shapeUserDatas(NULL)
	{
	}

	PxF32 chassisMass;
	PxVec3 chassisDims;
	PxVec3 chassisMOI;
	PxVec3 chassisCMOffset;
	PxMaterial* chassisMaterial;
	PxFilterData chassisSimFilterData;  //word0 = collide type, word1 = collide against types, word2 = PxPairFlags

	PxF32 wheelMass;
	PxF32 wheelWidth;
	PxF32 wheelRadius;
	PxF32 wheelMOI;
	PxMaterial* wheelMaterial;
	PxU32 numWheels;
	PxFilterData wheelSimFilterData;	//word0 = collide type, word1 = collide against types, word2 = PxPairFlags

	ActorUserData* actorUserData;
	ShapeUserData* shapeUserDatas;
};