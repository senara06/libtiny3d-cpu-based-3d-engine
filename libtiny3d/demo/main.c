#include "canvas.h"
#include "math3d.h"
#include "renderer.h"
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIDTH 400
#define HEIGHT 400
#define NUM_FRAMES 60

int main() {
    for (int frame = 0; frame < NUM_FRAMES; ++frame) {
        float t = (float)frame / NUM_FRAMES;
        canvas_t* canvas = create_canvas(WIDTH, HEIGHT);

        // Orbit center (light source)
        float orbit_cx = WIDTH / 2.0f;
        float orbit_cy = HEIGHT / 2.0f;
        float orbit_radius = 90.0f;

        // Soccer ball and cube are always separated by 120 degrees (2*PI/3)
        float soccer_angle = 2 * M_PI * t;
        float cube_angle = soccer_angle + 2 * M_PI / 3; // 120 degrees ahead

        // Soccer ball position (on the orbit)
        float soccer_cx = orbit_cx + cos(soccer_angle) * orbit_radius;
        float soccer_cy = orbit_cy + sin(soccer_angle) * orbit_radius;

        // Cube position (on the same orbit, offset)
        float cube_cx = orbit_cx + cos(cube_angle) * orbit_radius;
        float cube_cy = orbit_cy + sin(cube_angle) * orbit_radius;

        // Soccer ball transformation (rotates as it orbits)
        float scale_soccer = 29.0f;
        float radius = 150.0f;
        mat4_t soccer_tr = mat4_mul(mat4_rotate_y(t * 2 * M_PI), mat4_rotate_x(t * M_PI));

        // Cube transformation (rotates as it orbits)
        float scale_cube = 36.0f;
        mat4_t cube_rot = mat4_mul(mat4_rotate_y(-t * 2 * M_PI), mat4_rotate_x(-t * M_PI));
        mat4_t cube_tr = cube_rot;

        // Lighting: light source in 3D, slightly in front
        vec3_t light_pos = vec3(0.0f, 0.0f, 120.0f);

        // Draw soccer ball
        render_wireframe(canvas, soccer_vertices, soccer_edges, 60, 90, soccer_tr, soccer_cx, soccer_cy, scale_soccer, radius, light_pos);

        // Draw cube
        render_wireframe(canvas, cube_vertices, cube_edges, 8, 12, cube_tr, cube_cx, cube_cy, scale_cube, radius, light_pos);

        // Draw the fixed light dot at the orbit center
        for (float dy = -3; dy <= 3; dy++)
            for (float dx = -3; dx <= 3; dx++)
                set_pixel_f(canvas, orbit_cx + dx, orbit_cy + dy, 1.0f);

        char fname[64];
        sprintf(fname, "frame_%03d.ppm", frame);
        save_canvas_to_ppm(canvas, fname);
        destroy_canvas(canvas);
    }
    return 0;
}
