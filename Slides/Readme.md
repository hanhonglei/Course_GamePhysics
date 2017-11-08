- This article cites the page [Learning Physics Modeling with PhysX. Ch1- Starting with PhysX 3 SDK](https://www.linkedin.com/pulse/learning-physics-modeling-physx-ch1-starting-3-sdk-krishna-kumar/) from Krishna Kumar who is the author of book [Learning Physics Modeling with PhysX](https://www.amazon.com/Learning-Physics-Modeling-PhysX-Krishna/dp/1849698147). 

# Brief history

PhysX SDK is a mature physics engine, which has been under development since 2004. It was developed by Ageia with the purchase of ETH Zurich spin-off NovodeX. Ageia was a fabless semiconductor company and the first company that developed a dedicated co-processor capable of performing physics calculations , which was much faster than the general purpose CPUs available at that time.

The intention of Ageia was to sell PPU (Physics Processing Unit) cards much like the dedicated GPU (Graphics Processing Unit) cards that we buy today. It developed the PhysX software SDK (formerly NovodeX SDK) to harness the processing power of a PPU. The company also licensed out the PhysX SDK as a physics middleware library for game production. Unfortunately, the PPU cards didn't sell very well commercially in the market. On February 4, 2008, Nvidia announced that it would acquire Ageia. On February 13, 2008, the merger was finalized. The PhysX engine is now known as Nvidia PhysX. The potential reason of Ageia acquisition by Nvidia was to implement PhysX on top of their CUDA architecture enabled GPU(s), for hardware-accelerated physics processing. The PhysX GPU acceleration is exclusive to Nvidia GPU(s), which gives Nvidia an edge over its competitors; that is, GPU manufacturers such as ATI/AMD.

PhysX SDK 3.3.0 is the latest release at the time of writing this book. PhysX 3.x features a new modular architecture and a completely rewritten PhysX engine.

It provides a significant boost in overall performance as well as efficiency. It is a heavily-modified version written to support multiple platforms but has a single base code. Supported platforms include Windows; Linux; Mac OS X; game consoles such as XBOX 360 and PS3; and even Android-powered handheld devices. PhysX 3.3.0 added support for new platforms such as Xbox One, PS 4, Nintendo Wii U, Apple iOS, PS Vita, and Windows RT. PhysX SDK 3.x has undergone architecture and API improvement, and the code is cleaned at many levels to get rid of obsolete and legacy features and to integrate new physics capabilities.

# PhysX features

Nvidia PhysX is a state-of-the-art physics engine, which provides the following features:

## Rigid body dynamics
Rigid body dynamics is the most essential aspect of physics simulation, and makes use of physics concepts such as position, velocity, acceleration, forces, momentum, impulse, friction, collision, constraints, and gravity. These properties give us the power to simulate or mimic real-world physics scenarios.
## Character controller
Character controller is a special type of physics collider, which is mainly used for third-person or first-person player control, or any other kinematic body that may want to take advantage of the properties associated with the character controller.
## Vehicle dynamics
Vehicle dynamics gives you the capability to simulate vehicle physics by using spherical wheel shapes that can simulate sophisticated tire friction models. A joint-based suspension system is used for vehicle suspension.
## Particles and fluid simulation
Two of the most exciting features of PhysX are particles and fluid simulation. These features can be used to achieve a vast variety of cinematic effects. Particles can used for creating effects such as fire, spark, and debris, whereas fluid particles, also known as SPH(Smoothed Particle Hydrodynamics), are used to simulate liquid, gases, smoke, or any other SPH-based particle effect.
##Cloth simulation
This feature allows you to simulate realistic cloth, which can be used for cloth simulation of the characters in the game or any other cloth-based objects, such as flags and curtains. These cloth objects can also be stretched, torn, or attached to other physical bodies.
## Softbody simulation
This feature allows you to simulate volumetric deformable objects.
 
# New in PhysX 3

Notable features in PhysX 3 are as follows:

1. Automatic and efficient multithreading, and a unified code base for all supported platforms.
Improved task manager and a managed-thread pool that is optimized to harness the processing capability of multi-core processors on all platforms.

1. A new aggregate concept in which multiple PhysX actors can be combined into one entity having a common collision boundary, which simplifies processing when large numbers of objects are involved.

1. A new binary in-place serialization by which we can efficiently insert the PhysX actors into a scene with minimal data copying and without extra memory allocation. Creation and destruction of actors is now decoupled from the insertion and removal of scenes, thus allowing flexible asset management strategies.

1. A highly optimized physics runtime that has better a response time, with lower memory footprints.

1. A new release of PhysX Visual Debugger (PVD) that allows for better performance profiling and in-depth memory analysis with enhanced visualization of all PhysX content across all major platforms.

1. A full vehicle model that includes components such as engine, clutch, gears, autobox, differential, wheels, tires, suspension, and chassis. 

# Summary

This chapter enlightened us with all of the basic PhysX-related information. We learned how to register as a Nvidia developer and download the PhysX SDK from the Nvidia website. We also learned how to include the PhysX SDK files in Visual C++ 2010 for compiling PhysX programs.