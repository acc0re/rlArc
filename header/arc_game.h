#ifndef ARC_GAME_H
#define ARC_GAME_H

#define ARC_ENGINE_UI_VISIBLE true

#pragma GCC diagnostic ignored "-Wunused-variable"
#include "raylib.h"
#pragma GCC diagnostic pop

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define WINDOW_TITLE "rlArc"


void ArcGameInit(int screenWidth, int screenHeight);
void ArcGameUpdate(float deltaTime);
void ArcGameDraw(void);
void ArcGameUnload(void);

void ArcDrawTaskbar(void);


#endif // ARC_GAME_H
