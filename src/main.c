#include "arc_game.h"

int main(void) {
    ArcGameInit(1280, 720);

    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        ArcGameUpdate(deltaTime);
        ArcGameDraw();
    }

    ArcGameUnload();

    return 0;
}