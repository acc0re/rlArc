//
// Created by Alexander Chabowski on 30.11.24.
//
#include "ui/arc_ui_manager.h"
#include "ui/mainmenu/arc_ui_mainmenu.h"
#include "ui/mainmenu/arc_ui_tilemap.h"


static UIState currentState;

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
    default:
        currentState = UI_STATE_MAIN_MENU;
    }
}

void ArcUIManagerUnload(void)
{
    // Unload UI components here
}

void ArcUIManagerSetState(const UIState state)
{
    currentState = state;
}