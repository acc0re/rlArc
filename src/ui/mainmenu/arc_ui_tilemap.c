//
// Created by Alexander Chabowski on 30.11.24.
//
#include "raygui.h"

#include "ui/arc_ui_manager.h"
#include "ui/mainmenu/arc_ui_tilemap.h"

void ArcDrawTilemapMenu(void)
{
    ArcDrawTilemapTaskbar();
}

static void ArcDrawTilemapTaskbar(void)
{
    const int taskbarHeight = 60;
    const Rectangle taskbarRect = {0, 0, GetScreenWidth(), taskbarHeight};

    // Draw taskbar background
    GuiPanel(taskbarRect, "#97#Tilemap Editor");

    // Draw taskbar buttons
    if (GuiButton((Rectangle){10, 30, 20, 20}, "#118#"))
    {
        ArcUIManagerSetState(UI_STATE_MAIN_MENU);
    }
}