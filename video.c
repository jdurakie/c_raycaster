#include "raylib.h"

#include <unistd.h>

void initialize_video (int width, int height){
    const int screenWidth = width;
    const int screenHeight = height;
    InitWindow(screenWidth, screenHeight, "raytrace");
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
    BeginDrawing();
    SetTargetFPS(1);
}

void draw_pixel(int X, int Y, int R, int G, int B){
    DrawPixel(X, Y, BLACK);
}

void flip(void){
    EndDrawing();
}

void exit_video(void){
    CloseWindow();
}

