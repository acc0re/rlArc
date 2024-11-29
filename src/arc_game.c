#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arc_game.h"
#include "array.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


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

    ClearBackground(BLACK);


    ArcDrawTaskbar();

    DrawFPS(GetScreenWidth() * 0.935, 5);

    EndDrawing();
}

// Unload the game resources
void ArcGameUnload(void)
{
    CloseWindow();
}

void ArcDrawTaskbar()
{
    constexpr int taskbarHeight = 60;
    const Rectangle taskbarRect = {0, 0, GetScreenWidth(), taskbarHeight};

    // Draw taskbar background
    GuiPanel(taskbarRect, "rlArc");

    // Draw taskbar buttons
    if (GuiButton((Rectangle){10, 30, 100, 20}, "Tilemap"))
    {
       printf("Button 1 clicked\n");
    }
    if (GuiButton((Rectangle){120, 30, 100, 20}, "Character"))
    {
        printf("Button 2 clicked\n");
    }
}
