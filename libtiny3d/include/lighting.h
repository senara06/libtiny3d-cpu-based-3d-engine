// File: include/lighting.h
#ifndef LIGHTING_H
#define LIGHTING_H

#include "math3d.h"

typedef struct {
    vec3_t direction;  // Must be normalized
    float intensity;   // Scale (0.0 to 1.0)
} light_t;

// Computes the Lambertian intensity for an edge given a light
float compute_lambert_intensity(vec3_t edge_dir, light_t light);

#endif // LIGHTING_H
