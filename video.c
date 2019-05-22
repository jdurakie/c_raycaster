#include "raylib.h"

#include <unistd.h>

// Start drawing
void initialize_video (int width, int height){
    const int screenWidth = width;
    const int screenHeight = height;
    InitWindow(screenWidth, screenHeight, "raytrace");
    BeginDrawing();
    ClearBackground(BLACK);
}
// Draw a pixel on the back buffer
void draw_pixel(int X, int Y, int R, int G, int B){
    DrawPixel(X, Y, BLUE);
}

// Flip the back and front buffer and clear the back buffer
void flip(void){
    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
}

// Stop drawing
void exit_video(void){
    CloseWindow();
}

