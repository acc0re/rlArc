#ifndef ARC_GAME_H
#define ARC_GAME_H

#include "raylib.h"


#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define WINDOW_TITLE "RlArc"


void ArcGameInit(int screenWidth, int screenHeight);
void ArcGameUpdate(float deltaTime);
void ArcGameDraw(void);
void ArcGameUnload(void);


#endif // ARC_GAME_H