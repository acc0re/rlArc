#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (736)
#define WINDOW_TITLE "RlArc"


void InitGame(int screenWidth, int screenHeight);
void UpdateGame(void);
void DrawGame(void);
void UnloadGame(void);
Color ColorFromHex(const char *hex);

int **update(RenderTexture2D screen, int **cells, int **updated_cells, int size, bool with_progress);


#endif // GAME_H