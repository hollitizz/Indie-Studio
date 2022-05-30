/*******************************************************************************************
*
*   raylib [models] example - first person maze
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "../_deps/raylib-build/raylib/include/raylib.h"

#include <stdlib.h>           // Required for: free()

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - first person maze");

    // Define the camera to look into our 3d world
    Camera camera = { { 0.0f, 40.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 25.0f, 0 };

    Image imMap = LoadImage("assets/map_bomb.png");      // Load cubicmap image (RAM)
    Texture2D cubicmap = LoadTextureFromImage(imMap);       // Convert image to texture to display (VRAM)
    Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
    Model model = LoadModelFromMesh(mesh);

    // NOTE: By default each cube is mapped to one part of texture atlas
    Texture2D texture = LoadTexture("assets/cubicmap_atlas.png");    // Load map texture
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;             // Set map diffuse texture

    // Get map image data to be used for collision detection
    Color *mapPixels = LoadImageColors(imMap);
    UnloadImage(imMap);             // Unload image from RAM

    // Vector2 mapDeplacement = {cubicmap.width, cubicmap.height};
    Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };  // Set model position
    Vector3 playerPosition = { -15.0f, 0.5f, -7.0f };  // Set player position
    SetCameraMode(camera, CAMERA_THIRD_PERSON);     // Set camera mode

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        Vector3 oldCamPos = playerPosition;    // Store old camera position
        if (IsKeyDown(KEY_W)) playerPosition.z -= 0.1;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 0.1;
        if (IsKeyDown(KEY_S)) playerPosition.z += 0.1;
        if (IsKeyDown(KEY_D)) playerPosition.x += 0.1;
        UpdateCamera(&camera);      // Update camera

        // Check player collision (we simplify to 2D collision detection)
        Vector2 playerPos = { playerPosition.x, playerPosition.z };
        float playerRadius = 0.25f;  // Collision radius (player is modelled as a cilinder for collision)

        int playerCellX = (int)(playerPos.x - mapPosition.x + 0.5f);
        int playerCellY = (int)(playerPos.y - mapPosition.z + 0.5f);

        // Out-of-limits security check
        if (playerCellX < 0) playerCellX = 0;
        else if (playerCellX >= cubicmap.width) playerCellX = cubicmap.width - 1;

        if (playerCellY < 0) playerCellY = 0;
        else if (playerCellY >= cubicmap.height) playerCellY = cubicmap.height - 1;

        // Check map collisions using image data and player position
        // TODO: Improvement: Just check player surrounding cells for collision
        for (int y = 0; y < cubicmap.height; y++)
        {
            for (int x = 0; x < cubicmap.width; x++)
            {
                if ((mapPixels[y*cubicmap.width + x].r == 255) &&       // Collision: white pixel, only check R channel
                    (CheckCollisionCircleRec(playerPos, playerRadius,
                    (Rectangle){ mapPosition.x - 0.5f + x*1.0f, mapPosition.z - 0.5f + y*1.0f, 1.0f, 1.0f })))
                {
                    // Collision detected, reset camera position
                    playerPosition = oldCamPos;
                }
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawModel(model, mapPosition, 1.0f, WHITE);                     // Draw maze map
                DrawCube(playerPosition, 0.5, 1, 0.5, RED);               // Draw player
            EndMode3D();

            DrawTextureEx(cubicmap, (Vector2){ GetScreenWidth() - cubicmap.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);

            // Draw player position radar
            DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadImageColors(mapPixels);   // Unload color array

    UnloadTexture(cubicmap);        // Unload cubicmap texture
    UnloadTexture(texture);         // Unload map texture
    UnloadModel(model);             // Unload map model

    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}