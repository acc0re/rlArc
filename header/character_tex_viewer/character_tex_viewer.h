//
// Created by User on 27.12.2024.
//

#ifndef CHARACTER_TEX_VIEWER_H
#define CHARACTER_TEX_VIEWER_H

void CharacterTexViewerInit(void);

void CharacterTexViewerUpdate(float deltaTime);

void CharacterTexViewerDraw(void);

void CharacterTexViewerUnload(void);

static void DrawScaleText(float scale);

static void ZoomSpriteSheet(void);

static void Drag(void);

static void SelectCell(void);

static void DrawLastSelectedCell(void);

#endif //CHARACTER_TEX_VIEWER_H
