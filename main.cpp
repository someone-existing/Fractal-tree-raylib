#include "raylib.h"
#include <cmath>

int screenWidth = 800;
int screenHeight = 450;
float forkangle = PI/8;
int recursiondepth = 1;
float calc(float i, float ib, float o){
    return (i/ib)*o;
} 
void DrawTree(int startposx, int startposy, float angle, int depth, int r, int g, int b){
    if(depth > 0){
        float len = calc(depth, recursiondepth, 60);
        float thic = calc(depth, recursiondepth, 5);
        float endposx = startposx + cos(angle) * len;
        float endposy = startposy + sin(angle) * len;
    
        DrawLineEx(Vector2{startposx, startposy}, Vector2{endposx, endposy}, thic, {r, g, b, 255});
        DrawTree(endposx, endposy, angle - forkangle, depth - 1, r-70, g-10, b-50);
        DrawTree(endposx, endposy, angle + forkangle, depth - 1, r-70, g-10, b-50);
    }
}

int main(int argc, char* argv[])
{
    InitWindow(screenWidth, screenHeight, "Fractal tree");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({0, 0, 0, 255});

        DrawTree(screenWidth/2, screenHeight, -PI/2, recursiondepth, 255, 255, 255);
        if(IsKeyPressed(KEY_UP)){
            recursiondepth += 1;
        }
        if(IsKeyPressed(KEY_DOWN)){
            recursiondepth -= 1;
        }
        if(IsKeyDown(KEY_RIGHT)){
            forkangle += 0.001;
        }
        if(IsKeyDown(KEY_LEFT)){
            forkangle -= 0.001;
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}