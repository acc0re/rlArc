#include "arc_game.h"
#include "ui/arc_ui_manager.h"
#include "raygui/raygui.h"

#define ARC_ENGINE_DRAW_FPS false

// Initialize the game
void ArcGameInit(const int screenWidth, const int screenHeight)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

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
    ClearBackground(BLACK);

    if (ARC_ENGINE_UI_VISIBLE)
    {
        //ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        ArcUIManagerDraw();
    }

    BeginDrawing();


    if (ARC_ENGINE_DRAW_FPS)
    {
        DrawFPS(GetScreenWidth() * 0.935, 5);
    }

    EndDrawing();
}

// Unload the game resources
void ArcGameUnload(void)
{
    CloseWindow();
}
