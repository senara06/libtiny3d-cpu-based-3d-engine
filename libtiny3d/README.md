libtiny3d: 3D Software Renderer Library

Overview

libtiny3d is a lightweight, pure C software 3D graphics engine developed for the University of Peradeniya CO1020 course.
It implements a complete software rendering pipeline from scratch—no OpenGL, no DirectX, just math, code, and pixels!

Features include:

A floating-point canvas system for smooth, anti-aliased lines

Custom 3D vector and matrix math library

Wireframe rendering of 3D objects, with circular viewport clipping

Lambertian lighting for realistic edge brightness

Animation and demo programs for each project task

Project Structure

libtiny3d/
├── include/
│   ├── canvas.h
│   ├── math3d.h
│   ├── renderer.h
│   └── tiny3d.h
├── src/
│   ├── canvas.c
│   ├── math3d.c
│   ├── renderer.c
│   └── lighting.c
├── demo/
│   ├── clock_face.c     # Task 1: clock face demo
│   ├── cube_demo.c      # Task 2: cube math/transform demo
│   ├── soccer_demo.c    # Task 3: soccer ball wireframe demo
│   └── main.c           # Task 4: lighting/polish demo
├── build/
│   ├── libtiny3d.a
│   ├── clock_face
│   ├── cube_demo
│   ├── soccer_demo
│   └── main
├── documentation/
│   └── GroupXX_report.pdf
├── README.md
└── Makefile
Building the Library and Demos
Requirements
GCC or compatible C compiler

GNU Make

To Build Everything

make

This will:

Compile all source files in src/

Archive them into build/libtiny3d.a

Build all demo executables in build/

To Build Only the Library

make build/libtiny3d.a

To Build a Specific Demo
make build/clock_face
make build/cube_demo
make build/soccer_demo
make build/main
To Clean All Build Artifacts

make clean
Running the Demos
Each demo produces images (and/or animations) in the current directory.

Demo Executable	Description	How to Run
build/clock_face	Draws a clock face with anti-aliased lines	./build/clock_face
build/cube_demo	Shows 3D cube math and manual transforms	./build/cube_demo
build/soccer_demo	Rotating soccer ball wireframe demo	./build/soccer_demo
build/main	Full animated, lit, multi-object demo	./build/main
Each demo will output .ppm images. You can convert these to GIF with ImageMagick:
convert -delay 5 -loop 0 frame_*.ppm animation.gif
Using the Library in Your Own Code
Add -Iinclude to your compiler flags.

Link against libtiny3d.a with -Lbuild -ltiny3d.

Include the headers you need:

c
#include "canvas.h"
#include "math3d.h"
#include "renderer.h"
Example compile command:

text
gcc -Iinclude -Lbuild -ltiny3d -lm -o mydemo mydemo.c
Features
Anti-aliased, thick lines with sub-pixel precision (canvas & DDA line drawing)

3D vector and matrix math (including spherical, normalization, SLERP)

3D object wireframe rendering (with clipping and projection)

Lambertian lighting for wireframes (edges facing the light are brighter)

Animation framework (circular paths, smooth rotation, Bezier available)

Modular design—easy to extend and use in other C projects

Example Output


Notes
No external graphics libraries are used—everything is implemented from scratch.

For full implementation details, see the report in documentation/GroupXX_report.pdf.

Please cite and describe any AI tool usage in the report as per the project guidelines.

Enjoy building and exploring 3D graphics with libtiny3d!