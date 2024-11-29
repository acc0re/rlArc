#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arc_game.h"
#include "array.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "utils/arc_utils_color.h"

// Define colors used in the game
const Color COLOR_GRID = {40, 40, 40, 255};

// Initialize the game
void ArcGameInit(const int screenWidth, const int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "rlArc");
    SetTargetFPS(60);
}

// Update the game state
void ArcGameUpdate(float deltaTime)
{

}

// Draw the game state
void ArcGameDraw(void)
{
    BeginDrawing();

    EndDrawing();
}

// Unload the game resources
void ArcGameUnload(void)
{
    CloseWindow();
}