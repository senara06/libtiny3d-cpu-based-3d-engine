#include "canvas.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static float clamp(float v, float a, float b) { return v < a ? a : v > b ? b : v; }

static void add_pixel_intensity(canvas_t* canvas, int ix, int iy, float intensity) {
    if (ix >= 0 && ix < canvas->width && iy >= 0 && iy < canvas->height)
        canvas->pixels[iy][ix] = clamp(canvas->pixels[iy][ix] + intensity, 0.0f, 1.0f);
}

canvas_t* create_canvas(int width, int height) {
    canvas_t* c = malloc(sizeof(canvas_t));
    c->width = width; c->height = height;
    c->pixels = malloc(height * sizeof(pixel_brightness_t*));
    for (int y = 0; y < height; ++y)
        c->pixels[y] = calloc(width, sizeof(pixel_brightness_t));
    return c;
}

void destroy_canvas(canvas_t* c) {
    for (int y = 0; y < c->height; ++y) free(c->pixels[y]);
    free(c->pixels); free(c);
}

void set_pixel_f(canvas_t* c, float x, float y, float intensity) {
    intensity = clamp(intensity, 0.0f, 1.0f);
    int x0 = (int)floorf(x), y0 = (int)floorf(y);
    float fx = x - x0, fy = y - y0;
    float w00 = (1-fx)*(1-fy), w10 = fx*(1-fy), w01 = (1-fx)*fy, w11 = fx*fy;
    int wx[4] = {x0, x0+1, x0, x0+1}, wy[4] = {y0, y0, y0+1, y0+1};
    float w[4] = {w00, w10, w01, w11};
    for(int i=0;i<4;i++)
        add_pixel_intensity(c, wx[i], wy[i], intensity*w[i]);
}

void draw_line_f(canvas_t* c, float x0, float y0, float x1, float y1, float thickness) {
    draw_line_f_intensity(c, x0, y0, x1, y1, thickness, 1.0f);
}

void draw_line_f_intensity(canvas_t* c, float x0, float y0, float x1, float y1, float thickness, float intensity) {
    float dx = x1-x0, dy = y1-y0;
    float steps = fmaxf(fabsf(dx), fabsf(dy));
    if (steps < 1) steps = 1;
    float xinc = dx/steps, yinc = dy/steps;
    float nx = -dy, ny = dx;
    float len = sqrtf(nx*nx + ny*ny);
    if (len > 0) { nx /= len; ny /= len; }
    for (int i = 0; i <= (int)steps; ++i) {
        float cx = x0 + xinc*i, cy = y0 + yinc*i;
        for (float t = -thickness/2; t <= thickness/2; t += 0.5f)
            set_pixel_f(c, cx + nx*t, cy + ny*t, intensity);
    }
}

void save_canvas_to_ppm(const canvas_t* c, const char* filename) {
    FILE* f = fopen(filename, "w");
    fprintf(f, "P3\n%d %d\n255\n", c->width, c->height);
    for (int y = 0; y < c->height; ++y)
        for (int x = 0; x < c->width; ++x) {
            int v = (int)(c->pixels[y][x]*255.0f);
            if (v>255) v=255; 
            if (v<0) v=0;
            fprintf(f, "%d %d %d ", v, v, v);
        }
    fclose(f);
}

