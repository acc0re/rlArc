//
// Created by Alexander Chabowski on 30.11.24.
//
#include "raygui.h"
#include "ui/mainmenu/arc_ui_mainmenu.h"
#include "ui/arc_ui_manager.h"

// Draw the main menu
void ArcDrawMainMenu(void)
{
    ArcDrawMainMenuTaskbar();
}

// Draw the main menu taskbar
static void ArcDrawMainMenuTaskbar()
{
    const int taskbarHeight = 60;
    const Rectangle taskbarRect = {0, 0, GetScreenWidth(), taskbarHeight};

    // Draw taskbar background
    GuiPanel(taskbarRect, "rlArc");

    // Draw taskbar buttons
    if (GuiButton((Rectangle){10, 30, 100, 20}, "Tilemap"))
    {
        ArcUIManagerSetState(UI_STATE_TILEMAP);
    }
    if (GuiButton((Rectangle){120, 30, 100, 20}, "Character"))
    {
        ArcUIManagerSetState(UI_STATE_CHARACTER);
    }
}
