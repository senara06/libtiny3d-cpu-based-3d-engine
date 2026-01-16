// File: src/lighting.c
#include "lighting.h"
#include <math.h>

// Helper: normalize a vector
static vec3_t normalize(vec3_t v) {
    float len = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (len == 0) return v;
    return (vec3_t){ v.x/len, v.y/len, v.z/len };
}

float compute_lambert_intensity(vec3_t edge_dir, light_t light) {
    edge_dir = normalize(edge_dir);
    vec3_t light_dir = normalize(light.direction);
    float dot = edge_dir.x * light_dir.x + edge_dir.y * light_dir.y + edge_dir.z * light_dir.z;
    float intensity = fmaxf(0.0f, dot) * light.intensity; // Clamp to [0, 1]
    return intensity;
}
