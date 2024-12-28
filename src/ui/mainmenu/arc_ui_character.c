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

const char* zoom = "";

static bool fileDialogActive = false;
static FileDialogMode fileDialogMode = FILE_DIALOG_NONE;
static GuiWindowFileDialogState fileDialogState;

void ArcDrawCharacterMenu(void)
{
    internal_ArcDrawCharacterTaskbar();

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


                internal_HandleFileDialog((fullPath));
            }
            else
            {
                printf("Path too long\n");
                return;
            }
        }
    }

    internal_DrawCharacterProperties();
    internal_DrawFooterBar();
}

static void internal_ArcDrawCharacterTaskbar(void)
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

static void internal_DrawCharacterProperties(void)
{
    const int windowWidth = 300;
    const int windowHeight = GetScreenHeight();

    const Rectangle windowRect = {(float)(GetScreenWidth() - windowWidth), 60, (float)windowWidth, (float)windowHeight - 60};

    GuiWindowBox(windowRect, "Spritesheet Properties");

    static char columnText[128] = "4";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 100, windowWidth - 20, 20}, "Columns:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 100, windowWidth - 100, 30}, columnText, sizeof(columnText), false);

    static char rowText[128] = "4";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 140, windowWidth - 20, 20}, "Rows:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 140, windowWidth - 100, 30}, rowText, sizeof(rowText), false);

    static char spriteWidthText[128] = "64";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 180, windowWidth - 20, 20}, "Sprite Width:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 180, windowWidth - 100, 30}, spriteWidthText, sizeof(spriteWidthText), false);

    static char spriteHeightText[128] = "64";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 220, windowWidth - 20, 20}, "Sprite Height:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 220, windowWidth - 100, 30}, spriteHeightText, sizeof(spriteHeightText), false);

    GuiWindowBox((Rectangle){(float)(GetScreenWidth() - windowWidth), 320, (float)windowWidth, 220}, "Character Values");

    // HP
    static char hpText[128] = "100";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 380, windowWidth - 20, 20}, "HP:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 380, windowWidth - 100, 30}, hpText, sizeof(hpText), false);

    // ATK
    static char attackText[128] = "50";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 420, windowWidth - 20, 20}, "Attack:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 420, windowWidth - 100, 30}, attackText, sizeof(attackText), false);

    // DEF
    static char defenseText[128] = "30";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 460, windowWidth - 20, 20}, "Defense:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 460, windowWidth - 100, 30}, defenseText, sizeof(defenseText), false);

    // SPD
    static char speedText[128] = "10";
    GuiLabel((Rectangle){(float)(GetScreenWidth() - windowWidth) + 10, 500, windowWidth - 20, 20}, "Speed:");
    GuiTextBox((Rectangle){(float)(GetScreenWidth() - windowWidth) + 80, 500, windowWidth - 100, 30}, speedText, sizeof(speedText), false);
}

// Handle the selected file
static void internal_HandleFileDialog(const char* fileName)
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

//Footer bar
static void internal_DrawFooterBar(void)
{
    const int footerHeight = 24;
    const Rectangle footerRect = {0.0f, (float)(GetScreenHeight() - footerHeight), (float)GetScreenWidth(), (float)footerHeight};

    GuiPanel(footerRect, NULL);

    GuiLabel((Rectangle){10, GetScreenHeight() - footerHeight + 2, 80, 20}, "Zoom:");
    GuiTextBox((Rectangle){90, GetScreenHeight() - footerHeight + 2, 80, 20}, zoom, 32, false);


    static int selectedCell = 1;
    GuiLabel((Rectangle){250, GetScreenHeight() - footerHeight + 2, 120, 20}, "Selected Cell:");
    GuiTextBox((Rectangle){370, GetScreenHeight() - footerHeight + 2, 50, 20}, TextFormat("%d", selectedCell), 32, false);
}

void ArcUICharacterSetZoomText(float scale)
{
    char* scaleText[64];
    sprintf(scaleText, "Scale: %.2f", scale);

    zoom = scaleText;

}
