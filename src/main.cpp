#include "raylib.h"
#include <iostream>

static const size_t SCREEN_WIDTH = 640;
static const size_t SCREEN_HEIGHT = 480;
static const char *WINDOW_TITLE = "DeepDown";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
