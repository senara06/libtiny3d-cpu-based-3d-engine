// File: cube_demo.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "canvas.h"
#include "math3d.h"

#define WIDTH 400
#define HEIGHT 400
#define FRAMES 60
#define PI 3.14159265358979323846f

int main() {
    printf("Generating rotating cube frames...\n");

    float center_x = WIDTH / 2.0f;
    float center_y = HEIGHT / 2.0f;
    float scale = 100.0f;

    // Define cube vertices (8 corners)
    vec3_t cube_vertices[8] = {
        {-1, -1, -1}, {1, -1, -1},
        {1,  1, -1}, {-1, 1, -1},
        {-1, -1,  1}, {1, -1,  1},
        {1,  1,  1}, {-1, 1,  1}
    };

    // Define cube edges (pairs of indices)
    int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    for (int frame = 0; frame < FRAMES; frame++) {
        canvas_t* canvas = create_canvas(WIDTH, HEIGHT);
        if (!canvas) {
            fprintf(stderr, "Failed to create canvas for frame %d\n", frame);
            return 1;
        }

        float angle = 2 * PI * frame / FRAMES;

        mat4_t rot_y = mat4_rotate_y(angle);
        mat4_t rot_x = mat4_rotate_x(angle / 2);
        mat4_t transform = mat4_mul(rot_y, rot_x);

        for (int e = 0; e < 12; e++) {
            vec3_t v1 = cube_vertices[edges[e][0]];
            vec3_t v2 = cube_vertices[edges[e][1]];

            vec3_t r1 = mat4_mul_vec3(transform, v1);
            vec3_t r2 = mat4_mul_vec3(transform, v2);

            float x1 = center_x + r1.x * scale;
            float y1 = center_y - r1.y * scale;
            float x2 = center_x + r2.x * scale;
            float y2 = center_y - r2.y * scale;

            draw_line_f(canvas, x1, y1, x2, y2, 1.0f);
        }

        char filename[64];
        snprintf(filename, sizeof(filename), "frame_%02d.ppm", frame);
        save_canvas_to_ppm(canvas, filename);
        destroy_canvas(canvas);

        printf("Saved %s\n", filename);
    }

    printf("All frames generated.\n");
    return 0;
}
