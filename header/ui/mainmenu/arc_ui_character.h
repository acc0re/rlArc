#ifndef ARC_UI_CHARACTER_H
#define ARC_UI_CHARACTER_H

void ArcDrawCharacterMenu(void);
void ArcUICharacterSetZoomText(float scale);


static void internal_ArcDrawCharacterTaskbar(void);
static void internal_HandleFileDialog(const char *fileName);
static void internal_DrawCharacterProperties(void);
static void internal_DrawFooterBar(void);

#endif //ARC_UI_CHARACTER_H