#ifndef MATH3D_H
#define MATH3D_H

typedef struct {
    float x, y, z;
} vec3_t;

typedef struct {
    float m[4][4];
} mat4_t;

vec3_t vec3(float x, float y, float z);
mat4_t mat4_identity();
mat4_t mat4_rotate_x(float angle_rad);
mat4_t mat4_rotate_y(float angle_rad);
mat4_t mat4_translate(float tx, float ty, float tz);
mat4_t mat4_mul(mat4_t a, mat4_t b);
vec3_t mat4_mul_vec3(mat4_t m, vec3_t v);

// === Add these vector math helpers for lighting ===
vec3_t vec3_add(vec3_t a, vec3_t b);
vec3_t vec3_sub(vec3_t a, vec3_t b);
vec3_t vec3_scale(vec3_t v, float s);
float  vec3_dot(vec3_t a, vec3_t b);
vec3_t vec3_normalize(vec3_t v);

#endif // MATH3D_H
