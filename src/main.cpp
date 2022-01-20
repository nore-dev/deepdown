#include "raylib.h"
#include <stdint.h>
#include "Player.hpp"
#include "Level.hpp"

static const size_t SCREEN_WIDTH = 640;
static const size_t SCREEN_HEIGHT = 480;
static const char *WINDOW_TITLE = "DeepDown";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    SetTraceLogLevel(LOG_DEBUG);

    Player player = Player();
    Level level = Level();

    while (!WindowShouldClose())
    {

        player.update(level);

        BeginDrawing();
        ClearBackground(BLACK);

        level.draw();
        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
