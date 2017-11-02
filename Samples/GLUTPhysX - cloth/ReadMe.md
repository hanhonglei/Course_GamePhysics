# A sample about how to set up NVidia PhysX from scratch using FreeGLUT as graphic end

There are so few tutorials to show how to set up PhysX from scratch. This sample will show how to do it use [FreeGLUT](http://freeglut.sourceforge.net/)

This sample has been successfully complied on [Visual Studio 2015]( https://www.visualstudio.com)

## Configure IDE

Set include and lib directories of FreeGLUT and PhysX into the project’s `VC++ Directories` respectively in `Property Pages`.

Add necessary head files and libs into `Stdafx.h`

## Initialize FreeGLUT and PhysX
Please check `InitGL` and `InitPhysics` functions in `Graphics.cpp` and `Physics.cpp` respectively. Details about `PhysX` initialization can be found at `PhysX` `PhysXGuide.chm`.

## Step physics to simulate
Let `PhysX` to simulate the physics process in the scene before rendering it. 

## Connect physics with graphics
Use `OpenGL` to deal with rendering routine based on gestures get from `PhysX`. 
