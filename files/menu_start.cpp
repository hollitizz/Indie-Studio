/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "raylib.h"

typedef enum GameScreen { LOGO = 0, MENU, GAME, SETTINGS, RULES} GameScreen;


int map(void)
{
        // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - cubesmap loading and drawing");

    // Define the camera to look into our 3d world
    Camera camera = { { 8.0f, 30.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 40.0f, 0 };

    Image image = LoadImage("ressources/map_bomb.png");      // Load cubicmap image (RAM)
    Texture2D cubicmap = LoadTextureFromImage(image);       // Convert image to texture to display (VRAM)

    Mesh mesh = GenMeshCubicmap(image, (Vector3){ 1.0f, 1.0f, 1.0f });
    Model model = LoadModelFromMesh(mesh);

    // NOTE: By default each cube is mapped to one part of texture atlas
    Texture2D texture = LoadTexture("ressources/cubicmap_atlas.png");    // Load map texture
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;             // Set map diffuse texture

    Vector3 mapPosition = { -8.0f, 0.0f, -8.0f };          // Set model position

    UnloadImage(image);     // Unload cubesmap image from RAM, already uploaded to VRAM

    SetCameraMode(camera, CAMERA_FREE);  // Set an orbital camera mode

    SetTargetFPS(60);                       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())            // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);              // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawModel(model, mapPosition, 1.0f, WHITE);

            EndMode3D();

            DrawTextureEx(cubicmap, (Vector2){ screenWidth - cubicmap.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(screenWidth - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);

            DrawText("cubicmap image used to", 658, 90, 10, GRAY);
            DrawText("generate map 3d model", 658, 104, 10, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(cubicmap);    // Unload cubicmap texture
    UnloadTexture(texture);     // Unload map texture
    UnloadModel(model);         // Unload map model

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

int test(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    bool isClosed = false;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    GameScreen currentScreen = MENU;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        switch(currentScreen)
        {
            case MENU:
            {
                if (IsKeyPressed(KEY_A) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAME;
                }
                if (IsKeyPressed(KEY_Z) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAME;
                }
                if (IsKeyPressed(KEY_E) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = RULES;
                }
                if (IsKeyPressed(KEY_R) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = SETTINGS;
                }
                if (IsKeyPressed(KEY_S) || IsGestureDetected(GESTURE_TAP))
                {
                    ClearBackground(RAYWHITE);
                    isClosed = true;
                }
            } break;
            default: break;
        }
        if (isClosed) {
            break;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch(currentScreen)
            {
                case MENU:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawText("BOMBERMAN", 300, 100, 200, BLACK);
                    DrawText("PRESS A to Resume Game", 100, 300, 50, DARKGREEN);
                    DrawText("PRESS Z to New Game", 100, 450, 50, DARKGREEN);
                    DrawText("PRESS E to Rules", 100, 600, 50, DARKGREEN);
                    DrawText("PRESS R to Settings", 100, 750, 50, DARKGREEN);
                    DrawText("PRESS S to Quit", 100, 900, 50, DARKGREEN);

                } break;
                case GAME:
                {
                    CloseWindow();
                    map();

                } break;
                case SETTINGS:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                case RULES:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawText("BOMBERMAN", 300, 100, 200, BLACK);
                    DrawText("Commands :", 20, 350, 100, BLACK);
                    DrawText("Press Z to go Up", 50, 550, 50, BLACK);
                    DrawText("Press S to go Down", 50, 650, 50, BLACK);
                    DrawText("Press Q to go Right", 50, 750, 50, BLACK);
                    DrawText("Press D to go Left", 50, 850, 50, BLACK);
                    DrawText("Press Space to drop a bomb", 50, 950, 50, BLACK);
//-------------------------------------------------------------------------------------------------------------------------------------------
                    DrawText("Rules :", 980, 350, 100, BLACK);
                    DrawText("You have to be the last one !", 1000, 550, 50, BLACK);
                    DrawText("You have to explose all the other", 1000, 600, 50, BLACK);
                    DrawText("players.", 1000, 650, 50, BLACK);
                } break;
                default: break;
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

int main(int ac, char **av)
{
    test();
    return 0;
}