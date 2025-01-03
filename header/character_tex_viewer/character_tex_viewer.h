#ifndef CHARACTER_TEX_VIEWER_H
#define CHARACTER_TEX_VIEWER_H

#include "raylib.h"

void CharacterTexViewerInit(void);
void CharacterTexViewerUpdate(float deltaTime);
void CharacterTexViewerDraw(void);
void CharacterTexViewerUnload(void);
void CharacterTexViewerLoadSpritesheet(const char* fileName);
Texture2D CharacterTexViewerGetSpritesheet(void);

static void internal_ZoomSpriteSheet(void);
static void internal_Drag(void);
static void internal_SelectCell(void);
static void internal_DrawLastSelectedCell(void);
static void internal_DrawGrid(int spriteWidth, int spriteHeight);

#endif //CHARACTER_TEX_VIEWER_H
