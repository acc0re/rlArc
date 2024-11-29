#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "array.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// Define colors used in the game
const Color COLOR_GRID = {40, 40, 40, 255};
const Color COLOR_BG = {10, 10, 10, 255};
const Color COLOR_DIE_NEXT = {170, 170, 170, 255};

// Define grid dimensions
#define GRID_HEIGHT 90
#define GRID_WIDTH 160

static int** cells;
static int** updated_cells;
static RenderTexture2D screen;
static bool running = false;
static float updateTime = 0.0f;
static constexpr float updateInterval = 0.05f;

// Initialize the game
void InitGame(const int screenWidth, const int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Raylib - Conways Game of Life");
    SetTargetFPS(120);

    // Create arrays to store the current and next generation of cells
    cells = createArray(GRID_HEIGHT, GRID_WIDTH);
    updated_cells = createArray(GRID_HEIGHT, GRID_WIDTH);

    // Load the render texture
    screen = LoadRenderTexture(screenWidth, screenHeight);
    update(screen, cells, updated_cells, 10, false);
}

// Update the game state
void UpdateGame(void)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    float deltaTime = GetFrameTime();

    // Toggle running state with space key
    if (IsKeyReleased(KEY_SPACE))
    {
        running = !running;
        update(screen, cells, updated_cells, 10, false);
    }

    // Draw alive cells with left mouse button
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        const Vector2 pos = GetMousePosition();
        const int x = (int)pos.x;
        const int y = (int)pos.y;
        if ((x >= 0 && x < screenWidth) && (y >= 0 && y < screenHeight))
        {
            cells[y / 10][x / 10] = 1;
            update(screen, cells, updated_cells, 10, false);
        }
    }

    // Generate random pattern with right mouse button
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
    {
        srand((unsigned int)time(NULL)); // Seed the random number generator

        for (int i = 0; i < GRID_HEIGHT; i++)
        {
            for (int j = 0; j < GRID_WIDTH; j++)
            {
                cells[i][j] = rand() % 2; // Generate random number (0 or 1)
            }
        }
        update(screen, cells, updated_cells, 10, false);
    }

    // Update cells if the game is running
    if (running)
    {
        updateTime += deltaTime;
        if (updateTime >= updateInterval)
        {
            copyArray(cells, update(screen, cells, updated_cells, 10, true), GRID_HEIGHT, GRID_WIDTH);
            updateTime = 0.0f;
        }
    }
}

// Draw the game state
void DrawGame(void)
{
    BeginDrawing();
    DrawTextureRec(screen.texture, (Rectangle){0, 0, GetScreenWidth(), -GetScreenHeight()}, (Vector2){0, 0}, WHITE);


    // Display instructions when the game is not running
    if (!running)
    {
        const Color customColor = ColorFromHex("25D36F");
        DrawText("Press MOUSE LEFT  to draw alive cells", 10, 10, 20, customColor);
        DrawText("Press MOUSE RIGHT to generate random pattern", 10, 30, 20, customColor);
        DrawText("Press SPACE to start the simulation", 10, 50, 20, customColor);
    }

    EndDrawing();
}

// Unload the game resources
void UnloadGame(void)
{
    destroyArray(cells);
    destroyArray(updated_cells);
    UnloadRenderTexture(screen);
    CloseWindow();
}

// Update the cells based on Conway's Game of Life rules
int** update(const RenderTexture2D screen, int** cells, int** updated_cells, const int size, const bool with_progress)
{
    fillArray(updated_cells, GRID_HEIGHT, GRID_WIDTH, 0);

    BeginTextureMode(screen);
    ClearBackground(COLOR_GRID);
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            const int alive = sumArray(cells, GRID_HEIGHT, GRID_WIDTH, (Range){row - 1, col - 1, 3, 3}) - cells[row][
                col];
            Color color = cells[row][col] == 0 ? COLOR_BG : BLUE;

            if (cells[row][col] == 1)
            {
                if (alive < 2 || alive > 3)
                {
                    if (with_progress)
                    {
                        color = COLOR_DIE_NEXT;
                    }
                }
                else
                {
                    updated_cells[row][col] = 1;
                    if (with_progress)
                    {
                        color = BLUE;
                    }
                }
            }
            else
            {
                if (alive == 3)
                {
                    updated_cells[row][col] = 1;
                    if (with_progress)
                    {
                        color = BLUE;
                    }
                }
            }

            DrawRectangle(col * size, row * size, size - 1, size - 1, color);
        }
    }
    EndTextureMode();

    return updated_cells;
}

// Convert a hex color code to a Color object
Color ColorFromHex(const char* hex)
{
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    return (Color){r, g, b, 255};
}
