#ifndef ARC_UI_MANAGER_H
#define ARC_UI_MANAGER_H

#include "ui/arc_ui_states.h"

// Initialize the UI manager
void ArcUIManagerInit(void);

// Update the UI manager
void ArcUIManagerUpdate(float deltaTime);

// Draw the UI manager
void ArcUIManagerDraw(void);

// Unload the UI manager resources
void ArcUIManagerUnload(void);

// Set the current UI state
void ArcUIManagerSetState(UIState state);

// Get the current UI state
UIState ArcUIManagerGetState(void);

#endif // ARC_UI_MANAGER_H