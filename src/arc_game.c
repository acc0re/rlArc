#include "arc_game.h"
#include "ui/arc_ui_manager.h"
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

    if (ARC_ENGINE_UI_VISIBLE)
    {
        //ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        ArcUIManagerDraw();
    }

    DrawFPS(GetScreenWidth() * 0.935, 5);

    EndDrawing();
}

// Unload the game resources
void ArcGameUnload(void)
{
    CloseWindow();
}

