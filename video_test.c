#include "raylib.h"

#include <unistd.h>

int main(void){
    InitWindow(800, 600, "test");
    SetTargetFPS(60);
    for(int i = 0; i < 10; i ++){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawPixel(100 + i, 100, BLACK);
        EndDrawing();
        sleep(1);
    }
    CloseWindow();
}
