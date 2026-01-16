// File: main.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sin, cos
#include "canvas.h" // Include your canvas header

#define PI 3.14159265358979323846f

int main() {
    printf("Running clock_face_demo...\n");

    int width = 400;  // Increased width for better visualization
    int height = 400; // Increased height for better visualization
    float center_x = width / 2.0f;
    float center_y = height / 2.0f;
    float radius = fmin(width, height) / 2.0f - 20.0f; // Leave some margin from edges

    // Create a canvas
    canvas_t* clock_canvas = create_canvas(width, height);
    if (clock_canvas == NULL) {
        fprintf(stderr, "Failed to create canvas for clock face demo.\n");
        return 1;
    }

    // Draw lines going out from the center at 15-degree steps
    printf("Drawing lines at 15-degree steps...\n");
    float line_thickness = 1.5f; // Thickness for the radiating lines

    for (int i = 0; i < 360; i += 15) {
        // Convert degrees to radians
        float angle_rad = (float)i * PI / 180.0f;

        // Calculate the end point of the line
        float end_x = center_x + radius * cos(angle_rad);
        float end_y = center_y + radius * sin(angle_rad);

        // Draw the line from the center to the calculated end point
        draw_line_f(clock_canvas, center_x, center_y, end_x, end_y, line_thickness);
    }

    // Save the canvas content to a PPM file
    save_canvas_to_ppm(clock_canvas, "clock_face.ppm");

    // Clean up allocated memory
    destroy_canvas(clock_canvas);

    printf("clock_face_demo finished. Check 'clock_face.ppm' for results.\n");

    return 0;
}
