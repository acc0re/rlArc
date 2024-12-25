//
// Created by Alexander Chabowski on 25.12.24.
//

#ifndef ARC_GAME_STATE_MANAGER_H
#define ARC_GAME_STATE_MANAGER_H

#include "state/arc_game_states.h"

// Initialize the UI manager
void ArcGameStateManagerInit(void);

// Update the UI manager
void ArcGameStateManagerUpdate(float deltaTime);

// Draw the UI manager
void ArcGameStateManagerDraw(void);

// Unload the UI manager resources
void ArcGameStateManagerUnload(void);

// Set the current UI state
void ArcGameStateManagerSetState(GameState state);

// Get the current UI state
GameState ArcGameStateManagerGetState(void);

#endif // ARC_GAME_STATE_MANAGER_H
