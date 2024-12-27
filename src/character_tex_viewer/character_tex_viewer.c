#include "character_tex_viewer/character_tex_viewer.h"

#include "raylib.h"
#include <stdio.h>

static Texture2D spriteSheet;
static float scale = 2.0f;
static Vector2 spriteSheetPos = {100, 100};
static bool isDragging = false;
static float lastMouseX = 0.0f;
static float lastMouseY = 0.0f;

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
    ZoomSpriteSheet();
    Drag();
}


void CharacterTexViewerDraw(void)
{
    int spriteWidth = spriteSheet.width;
    int spriteHeight = spriteSheet.height;

    int gridSize = (int)(24 * scale); //TODO: Make sprite size configurable
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
    }
    else
    {
        DrawText("Fehler: Sprite-Sheet nicht geladen!", 10, 50, 20, RED);
    }
}


void CharacterTexViewerUnload(void)
{
    if (spriteSheet.id > 0)
    {
        UnloadTexture(spriteSheet);
    }
}

//Draw scale text
static void DrawScaleText(float scale)
{
    char scaleText[64];
    sprintf(scaleText, "Scale: %.2f", scale);

    int textWidth = MeasureText(scaleText, 20);

    DrawText(scaleText, GetScreenWidth() - textWidth - 10, 80, 20, SKYBLUE);
}

static void ZoomSpriteSheet(void)
{
    float mouseWheelMove = GetMouseWheelMove();
    if (mouseWheelMove != 0.0f)
    {
        scale += (int)mouseWheelMove;

        if (scale < 1) scale = 1;
        if (scale > 10) scale = 10;
    }
}

static void Drag()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
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
