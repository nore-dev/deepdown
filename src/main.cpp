#include "raylib.h"
#include <stdint.h>
#include "Player.hpp"

static const size_t SCREEN_WIDTH = 640;
static const size_t SCREEN_HEIGHT = 480;
static const char *WINDOW_TITLE = "DeepDown";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    SetTraceLogLevel(LOG_DEBUG);

    Player player = Player();
    Rectangle testRect = {10, 200, 100, 40};
    while (!WindowShouldClose())
    {

        player.update();

        BeginDrawing();
        ClearBackground(BLACK);

        player.draw();
        DrawRectangleRec(testRect, YELLOW);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
