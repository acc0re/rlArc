#include "character_tex_viewer/character_tex_viewer.h"

#include "raylib.h"
#include <stdio.h>

static Texture2D spriteSheet;
static float scale = 2.0f;
static Vector2 spriteSheetPos = {100, 100};
static bool isDragging = false;
static float lastMouseX = 0.0f;
static float lastMouseY = 0.0f;
static int cellSize = 24; //TODO: Make sprite size configurable

// Für die Anzeige der Zellenposition
static Vector2 selectedCell = {0, 0};

void CharacterTexViewerInit(void)
{
    const char* absolutePath = "X:/godot/timebound/Scenes/Character/Heroes/Yuki/Yuki.png";

    spriteSheet = LoadTexture(absolutePath);

    if (spriteSheet.id == 0)
    {
        printf("Error: Sprite-Sheet not found! Path: %s\n", absolutePath);
        return;
    }
}

void CharacterTexViewerUpdate(float deltaTime)
{
    //Zoom with Mousewheel
    ZoomSpriteSheet();

    //Drag with CTRL + Left Mouse Button
    Drag();

    //Select a cell with Left Mouse Button
    SelectCell();
}

void CharacterTexViewerDraw(void)
{
    int spriteWidth = spriteSheet.width;
    int spriteHeight = spriteSheet.height;

    int gridSize = (int)(cellSize * scale);
    Color gridColor = GRAY;

    if (spriteSheet.id > 0)
    {
        DrawTextureEx(spriteSheet, spriteSheetPos, 0.0f, scale, WHITE);

        for (int x = spriteSheetPos.x; x <= spriteSheetPos.x + spriteWidth * scale; x += gridSize)
        {
            DrawLine(x, spriteSheetPos.y, x, spriteSheetPos.y + spriteHeight * scale, gridColor);
        }

        for (int y = spriteSheetPos.y; y <= spriteSheetPos.y + spriteHeight * scale; y += gridSize)
        {
            DrawLine(spriteSheetPos.x, y, spriteSheetPos.x + spriteWidth * scale, y, gridColor);
        }

        DrawScaleText(scale);
        DrawLastSelectedCell();
    }
    else
    {
        DrawText("Error: Spritesheet could not be loaded!", 10, 50, 20, RED);
    }
}

void CharacterTexViewerUnload(void)
{
    if (spriteSheet.id > 0)
    {
        UnloadTexture(spriteSheet);
    }
}

// Zeichne den Text, der den aktuellen Zoomfaktor anzeigt
static void DrawScaleText(float scale)
{
    char scaleText[64];
    sprintf(scaleText, "Scale: %.2f", scale);

    int textWidth = MeasureText(scaleText, 20);

    DrawText(scaleText, GetScreenWidth() - textWidth - 10, 80, 20, SKYBLUE);
}

static void ZoomSpriteSheet(void)
{
    if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)))
    {
        float mouseWheelMove = GetMouseWheelMove();
        if (mouseWheelMove != 0.0f)
        {
            scale += (int)mouseWheelMove;

            if (scale < 1) scale = 1;
            if (scale > 10) scale = 10;
        }
    }
}

static void Drag()
{
    if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (!isDragging)
        {
            isDragging = true;
            lastMouseX = GetMouseX();
            lastMouseY = GetMouseY();
        }
        else
        {
            float deltaX = GetMouseX() - lastMouseX;
            float deltaY = GetMouseY() - lastMouseY;

            spriteSheetPos.x += deltaX;
            spriteSheetPos.y += deltaY;

            lastMouseX = GetMouseX();
            lastMouseY = GetMouseY();
        }
    }
    else
    {
        isDragging = false;
    }
}

static void SelectCell(void)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !isDragging)
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        int adjustedX = mouseX - spriteSheetPos.x;
        int adjustedY = mouseY - spriteSheetPos.y;

        int cellWidth = (int)(cellSize * scale);
        int cellHeight = (int)(cellSize * scale);

        selectedCell.x = adjustedX / cellWidth;
        selectedCell.y = adjustedY / cellHeight;

        int maxX = spriteSheet.width / cellSize;
        int maxY = spriteSheet.height / cellSize;

        if (selectedCell.x >= maxX) selectedCell.x = maxX - 1;
        if (selectedCell.y >= maxY) selectedCell.y = maxY - 1;

        if (selectedCell.x < 0) selectedCell.x = 0;
        if (selectedCell.y < 0) selectedCell.y = 0;
    }
}


static void DrawLastSelectedCell(void)
{
    int cellWidth = (int)(cellSize * scale);
    int cellHeight = (int)(cellSize * scale);

    int x = (int)(spriteSheetPos.x + selectedCell.x * cellWidth);
    int y = (int)(spriteSheetPos.y + selectedCell.y * cellHeight);

    DrawRectangleLines(x, y, cellWidth, cellHeight, MAGENTA);

    char text[64];
    sprintf(text, "Selected Cell: X = %i, Y = %i", (int)selectedCell.x, (int)selectedCell.y);

    int textWidth = MeasureText(text, 20);

    DrawText(text, GetScreenWidth() - textWidth - 10, 105, 20, SKYBLUE);
}
