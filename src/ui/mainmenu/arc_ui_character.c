#include <stddef.h>
#include "raygui/raygui.h"
#include "ui/arc_ui_manager.h"
#include "ui/mainmenu/arc_ui_character.h"
#include "raygui/raygui_icon_helper.h"

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "raygui/gui_window_file_dialog.h"

// State for the file dialog
static bool fileDialogActive = false;
static GuiWindowFileDialogState fileDialogState;

void ArcDrawCharacterMenu(void)
{
    ArcDrawCharacterTaskbar();

    // Draw file dialog if active
    if (fileDialogActive)
    {
        GuiWindowFileDialog(&fileDialogState);
        if (!fileDialogState.windowActive)
        {
            fileDialogActive = false;
            // Handle the selected file (fileDialogState.fileNameText)
        }
    }
}

static void ArcDrawCharacterTaskbar(void)
{
    const int taskbarHeight = 60;
    const Rectangle taskbarRect = {0, 0, GetScreenWidth(), taskbarHeight};

    // Draw taskbar background
    GuiPanel(taskbarRect, RGUI_ICON_TEXT(RAYGUI_ICON_PLAYER, "Character Editor"));

    // Draw taskbar buttons
    if (GuiButton((Rectangle){10, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_ARRAY_LEFT_FILL)))
    {
        ArcUIManagerSetState(UI_STATE_MAIN_MENU);
    }

    // Add Character file
    if (GuiButton((Rectangle){40, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_FILE_ADD)))
    {
    }

    // Open Character file
    if (GuiButton((Rectangle){65, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_FILE_OPEN)))
    {
        fileDialogActive = true; // Activate file dialog
        fileDialogState = InitGuiWindowFileDialog(NULL); // Initialize file dialog state
        fileDialogState.windowActive = true; // Set the dialog to active
    }
}