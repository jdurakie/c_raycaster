#include "raylib.h"

#include <unistd.h>

int main(void){
    InitWindow(800, 600, "test");
    //SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for(int i = 0; i < 10; i ++){
        DrawPixel(100 + i, 100, BLACK);
    }
    EndDrawing();
    sleep(10);
    CloseWindow();
}
