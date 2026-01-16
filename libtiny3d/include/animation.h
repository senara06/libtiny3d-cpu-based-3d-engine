// File: include/animation.h
#ifndef ANIMATION_H
#define ANIMATION_H

#include "math3d.h"

// Cubic Bézier interpolation for 3D points
vec3_t bezier(vec3_t p0, vec3_t p1, vec3_t p2, vec3_t p3, float t);

#endif // ANIMATION_H
