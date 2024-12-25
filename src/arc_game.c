#include "arc_game.h"
#include "ui/arc_ui_manager.h"
#include "raygui/raygui.h"
#include "state/arc_game_states.h"
#include "state/arc_game_state_manager.h"

#define ARC_ENGINE_DRAW_FPS false

// Initialize the game
void ArcGameInit(const int screenWidth, const int screenHeight)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "rlArc");
    SetTargetFPS(60);

    ArcGameStateManagerInit();
}

// Update the game state
void ArcGameUpdate(float deltaTime)
{
    ArcGameStateManagerUpdate(deltaTime);
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

    /* TODO: Handle this in the specific game states
    if (ArcUIManagerGetState() == UI_STATE_CHARACTER)
    {
        DrawText("Character Editor", 10, 150, 20, SKYBLUE);
    }
    else if (ArcUIManagerGetState() == UI_STATE_TILEMAP)
    {
        DrawText("Tilemap Editor", 10, 150, 20, SKYBLUE);
    }
*/
    ArcGameStateManagerDraw();

    if (ARC_ENGINE_DRAW_FPS)
    {
        DrawFPS(GetScreenWidth() * 0.935, 5);
    }

    EndDrawing();
}

// Unload the game resources
void ArcGameUnload(void)
{
    ArcGameStateManagerUnload();
    CloseWindow();
}
