// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

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
#include "pvd/PxPvd.h"
#include "extensions/PxDefaultSimulationFilterShader.h"
#include "pvd/PxPvdTransport.h"
#include "PxScene.h"

#include "PxPhysicsAPI.h"
#include <vector>

//#include "PxTkFile.h"
//#include "PsString.h"
//#include "PsFPU.h"
//
//#include "PxToolkit.h"
#include "extensions/PxDefaultStreams.h"

#pragma comment(lib, "freeglut.lib")

#pragma comment(lib, "PhysX3DEBUG_X86.lib")
#pragma comment(lib, "PhysX3CommonDEBUG_X86.lib")
#pragma comment(lib, "PxFoundationDEBUG_X86.lib")
#pragma comment(lib, "PhysX3ExtensionsDEBUG.lib")
#pragma comment(lib, "PxPvdSDKDEBUG_x86.lib")
using namespace physx;