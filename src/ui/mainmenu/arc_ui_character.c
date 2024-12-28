#include <stdio.h>
#include "raygui/raygui.h"
#include "ui/arc_ui_manager.h"
#include "ui/mainmenu/arc_ui_character.h"
#include "raygui/raygui_icon_helper.h"

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "raygui/gui_window_file_dialog.h"
#include "character_tex_viewer/character_tex_viewer.h"

typedef enum
{
    FILE_DIALOG_NONE,
    FILE_DIALOG_OPEN,
    FILE_DIALOG_SAVE,
    FILE_DIALOG_SPRITESHEET,
} FileDialogMode;

static bool fileDialogActive = false;
static FileDialogMode fileDialogMode = FILE_DIALOG_NONE;
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
            fileDialogActive = false; // Close dialog when done
            char fullPath[2048];
            if (sizeof(fullPath) <= 2048)
            {
                snprintf(fullPath, sizeof(fullPath), "%s/%s", fileDialogState.dirPathText,
                         fileDialogState.fileNameText);


                HandleFileDialog((fullPath));
            }
            else
            {
                printf("Path too long\n");
                return;
            }
        }
    }
}

static void ArcDrawCharacterTaskbar(void)
{
    const int taskbarHeight = 60;
    const Rectangle taskbarRect = {0.0f, 0.0f, (float)GetScreenWidth(), (float)taskbarHeight};

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
        // TODO: Implement character file creation
    }

    // Open Character file
    if (GuiButton((Rectangle){65, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_FILE_OPEN)))
    {
        fileDialogMode = FILE_DIALOG_OPEN;
        fileDialogActive = true;
        fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
        fileDialogState.windowActive = true;
    }

    // Save Character file
    if (GuiButton((Rectangle){90, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_FILE_SAVE_CLASSIC)))
    {
        fileDialogMode = FILE_DIALOG_SAVE;
        fileDialogActive = true;
        fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
        fileDialogState.windowActive = true;
    }

    if (GuiButton((Rectangle){115, 30, 20, 20}, RGUI_ICON(RAYGUI_ICON_IMAGE)))
    {
        fileDialogMode = FILE_DIALOG_SPRITESHEET;
        fileDialogActive = true;
        fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
        fileDialogState.windowActive = true;
    }
}

// Handle the selected file
static void HandleFileDialog(const char* fileName)
{
    if (fileDialogMode == FILE_DIALOG_SPRITESHEET)
    {
        //Load Spritesheet to the Character Editor
        CharacterTexViewerLoadSpritesheet(fileName);
    }
    else if (fileDialogMode == FILE_DIALOG_SAVE)
    {
        //TODO; Implement saving of character file
        printf("File Saved: %s\n", fileName);
    }
}
