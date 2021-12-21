#include "raylib.h"
int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               
    while (!WindowShouldClose()){  
        BeginDrawing();
            ClearBackground(BLACK);
            
        EndDrawing();
    }
    CloseWindow();     



}
