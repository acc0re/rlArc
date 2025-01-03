//
// Created by Alexander Chabowski on 30.11.24.
//
#include "ui/arc_ui_manager.h"

#include "raygui/raygui.h"
#include "ui/mainmenu/arc_ui_mainmenu.h"
#include "ui/mainmenu/arc_ui_tilemap.h"
#include "ui/mainmenu/arc_ui_character.h"
#include "state/arc_game_state_manager.h"

static UIState currentState;

// Initialize the UI manager
void ArcUIManagerInit(void)
{
    currentState = UI_STATE_MAIN_MENU; // Set initial state
}

// Update the UI manager
void ArcUIManagerUpdate(float deltaTime)
{
    switch (currentState)
    {
    case UI_STATE_MAIN_MENU:
        // Update main menu components
        break;
    default:
        currentState = UI_STATE_MAIN_MENU;
    }
}

// Draw the UI manager
void ArcUIManagerDraw(void)
{
    // Draw UI components based on the current state
    switch (currentState)
    {
    case UI_STATE_MAIN_MENU:
        ArcDrawMainMenu();
        break;
    case UI_STATE_TILEMAP:
        ArcDrawTilemapMenu();
        break;
    case UI_STATE_CHARACTER:
        ArcDrawCharacterMenu();
        break;
    default:
        currentState = UI_STATE_MAIN_MENU;
    }
}

// Unload the UI manager resources
void ArcUIManagerUnload(void)
{

}

// Set the current UI state
void ArcUIManagerSetState(const UIState state)
{
    currentState = state;

    switch (currentState)
    {
    case UI_STATE_CHARACTER:
        ArcGameStateManagerSetState(GAME_STATE_CHARACTER_TEX_VIEWER);
        break;
    default:
        ArcGameStateManagerSetState(GAME_STATE_MAIN_MENU);
    }
}

//Gets the current UI State
UIState ArcUIManagerGetState(void)
{
    return currentState;
}
