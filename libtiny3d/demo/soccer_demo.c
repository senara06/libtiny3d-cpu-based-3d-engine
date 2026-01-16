#include <stdio.h>
#include <math.h>
#include "canvas.h"
#include "math3d.h"
#include "renderer.h"

#define WIDTH 400
#define HEIGHT 400
#define FRAMES 60
#define PI 3.14159265358979323846f

int main() {
    float center_x = WIDTH / 2.0f, center_y = HEIGHT / 2.0f;
    float scale = 80.0f;
    float radius = scale * 2.5f;

    for (int frame = 0; frame < FRAMES; frame++) {
        canvas_t* canvas = create_canvas(WIDTH, HEIGHT);
        float angle = 2 * PI * frame / FRAMES;
        mat4_t rot_y = mat4_rotate_y(angle);
        mat4_t rot_x = mat4_rotate_x(angle / 2);
        mat4_t transform = mat4_mul(rot_y, rot_x);

       vec3_t light_pos = vec3(center_x, center_y, 120.0f); // Light in front of the ball
    render_wireframe(
        canvas,
    soccer_vertices,
    soccer_edges,
    60,
    90,
    transform,
    center_x,
    center_y,
    scale,
    radius,
    light_pos
);

    

        char filename[64];
        snprintf(filename, sizeof(filename), "soccer_frame_%02d.ppm", frame);
        save_canvas_to_ppm(canvas, filename);
        destroy_canvas(canvas);
    }
    return 0;
}
