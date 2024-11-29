#include "game.h"

int main(void) {
    InitGame(1280, 720);

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    UnloadGame();

    return 0;
}