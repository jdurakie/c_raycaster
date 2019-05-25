#ifndef SCREEN
#define SCREEN

#include "raylib.h"

#include "lines.c"
#include "vectors.c"
#include "triangles.c"


void render_one_triangle(Triangle * T){
    Vector * focal_point = make_vector(SCREEN_HEIGHT / 2, 
                                       SCREEN_WIDTH / 2, 
                                       FOCAL_DISTANCE);
                                       
    for(int x = 0; x < SCREEN_WIDTH; x++){
        for(int y = 0; y < SCREEN_HEIGHT; y++){
            Vector * ray_end = make_vector(x, y, 0); //screen pixel coordinate
            Line * ray = make_line(focal_point, ray_end);
            Vector * intersection = triangle_line_intersection(T, ray);
            if(intersection != NULL){
                draw_pixel(x, y, 0, 0, 0);
            }
            free(ray_end);
            free(ray);
            free(intersection);
        }
    }
    free(focal_point);
}





#endif