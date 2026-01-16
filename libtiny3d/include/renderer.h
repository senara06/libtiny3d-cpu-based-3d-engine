#ifndef RENDERER_H
#define RENDERER_H

#include "canvas.h"
#include "math3d.h"

// Soccer ball geometry (arrays defined in renderer.c)
extern const vec3_t soccer_vertices[60];
extern const int soccer_edges[90][2];
extern const vec3_t cube_vertices[8];
extern const int cube_edges[12][2];


// Rendering functions
void project_vertex(const mat4_t* transform, const vec3_t* v, float* x, float* y, float* z);
int inside_circle(float x, float y, float cx, float cy, float r);
void render_wireframe(
    canvas_t* canvas,
    const vec3_t* vertices,
    const int edges[][2],
    int num_vertices,
    int num_edges,
    mat4_t transform,
    float center_x,
    float center_y,
    float scale,
    float radius,
    vec3_t light_pos // <-- Add this argument!
);


#endif

