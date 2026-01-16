// File: src/math3d.c
#include <math.h>
#include "math3d.h"

vec3_t vec3(float x, float y, float z) {
    vec3_t v = {x, y, z};
    return v;
}

mat4_t mat4_identity() {
    mat4_t m = {0};
    for (int i = 0; i < 4; i++) {
        m.m[i][i] = 1.0f;
    }
    return m;
}

mat4_t mat4_rotate_x(float angle_rad) {
    mat4_t m = mat4_identity();
    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    m.m[1][1] = c;
    m.m[1][2] = -s;
    m.m[2][1] = s;
    m.m[2][2] = c;

    return m;
}

mat4_t mat4_rotate_y(float angle_rad) {
    mat4_t m = mat4_identity();
    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    m.m[0][0] = c;
    m.m[0][2] = s;
    m.m[2][0] = -s;
    m.m[2][2] = c;

    return m;
}

mat4_t mat4_mul(mat4_t a, mat4_t b) {
    mat4_t result = {0};
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            for (int k = 0; k < 4; k++) {
                result.m[row][col] += a.m[row][k] * b.m[k][col];
            }
        }
    }
    return result;
}

vec3_t mat4_mul_vec3(mat4_t m, vec3_t v) {
    vec3_t result;
    result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
    result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
    result.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
    return result;
}
mat4_t mat4_translate(float tx, float ty, float tz) {
    mat4_t m = mat4_identity();
    m.m[3][0] = tx;
    m.m[3][1] = ty;
    m.m[3][2] = tz;
    return m;
}
vec3_t vec3_add(vec3_t a, vec3_t b) {
    return (vec3_t){a.x + b.x, a.y + b.y, a.z + b.z};
}
vec3_t vec3_sub(vec3_t a, vec3_t b) {
    return (vec3_t){a.x - b.x, a.y - b.y, a.z - b.z};
}
vec3_t vec3_scale(vec3_t v, float s) {
    return (vec3_t){v.x * s, v.y * s, v.z * s};
}
float vec3_dot(vec3_t a, vec3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
vec3_t vec3_normalize(vec3_t v) {
    float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len > 1e-6f)
        return (vec3_t){v.x / len, v.y / len, v.z / len};
    else
        return (vec3_t){0, 0, 0};
}


