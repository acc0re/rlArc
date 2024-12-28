//
// Created by Alexander Chabowski on 25.12.24.
//
#include "state/arc_game_state_manager.h"
#include "character_tex_viewer/character_tex_viewer.h"

static GameState currentState;

void ArcGameStateManagerInit(void)
{
    currentState = GAME_STATE_MAIN_MENU;
}

void ArcGameStateManagerUpdate(float deltaTime)
{
    switch (currentState)
    {
    case GAME_STATE_MAIN_MENU:
        // Update main menu components
        break;
    case GAME_STATE_TILEMAP_EDITOR:

        break;
    case GAME_STATE_CHARACTER_TEX_VIEWER:
        CharacterTexViewerUpdate(deltaTime);
        break;
    default:
        currentState = GAME_STATE_MAIN_MENU;
    }
}

void ArcGameStateManagerDraw(void)
{
    // Draw based on the current state
    switch (currentState)
    {
    case GAME_STATE_MAIN_MENU:

        break;
    case GAME_STATE_TILEMAP_EDITOR:

        break;
    case GAME_STATE_CHARACTER_TEX_VIEWER:
        CharacterTexViewerDraw();
        break;
    default:
        currentState = GAME_STATE_MAIN_MENU;
    }
}

void ArcGameStateManagerUnload(void)
{
    switch (currentState)
    {
    case GAME_STATE_MAIN_MENU:
        break;
    case GAME_STATE_CHARACTER_TEX_VIEWER:
        CharacterTexViewerUnload();
        break;
    case GAME_STATE_TILEMAP_EDITOR:
        break;
    }
}

void ArcGameStateManagerSetState(GameState state)
{
    ArcGameStateManagerUnload();

    currentState = state;

    switch (currentState)
    {
    case GAME_STATE_CHARACTER_TEX_VIEWER:
        CharacterTexViewerInit();
        break;
    }
}
