// /*
// ** EPITECH PROJECT, 2022
// ** Untitled (Workspace)
// ** File description:
// ** Raylib
// */

// #include <iostream>
// #include "Raylib.hpp"

// Raylib::Raylib()
// {}

// Raylib::~Raylib()
// {}

// void Raylib::createWindow(int width, int height, std::string title, size_t fps)
// {
//     _screenSize.first = width;
//     _screenSize.second = height;
//     InitWindow(_screenSize.first, _screenSize.second, title.c_str());
//     SetTargetFPS(fps);
//     SetExitKey(KEY_NULL);
// }

// void Raylib::closeWindow()
// {
//     CloseWindow();
// }

// Vector2 Raylib::getScreenSize() const
// {
//     return {
//         static_cast<float>(GetScreenWidth()),
//         static_cast<float>(GetScreenHeight())
//     };
// }


// bool Raylib::isOpen()
// {
//     return !WindowShouldClose();
// }


// void Raylib::beginDrawing()
// {
//     BeginDrawing();
// }

// void Raylib::endDrawing()
// {
//     EndDrawing();
// }

// void Raylib::start3D()
// {
//     BeginMode3D(_camera);
// }

// void Raylib::end3D()
// {
//     EndMode3D();
// }

// void Raylib::clearBackground()
// {
//     ClearBackground(WHITE);
// }

// void Raylib::clearBackground(Color color)
// {
//     ClearBackground(color);
// }

// void Raylib::setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
// {
//     _camera.position = pos;
//     _camera.target = target;
//     _camera.up = up;
//     _camera.fovy = fovy;
//     _camera.projection = projection;
//     updateCamera();
//     SetCameraMode(_camera, CAMERA_FREE);
// }

// Camera Raylib::getCamera() const
// {
//     return _camera;
// }

// void Raylib::updateCamera()
// {
//     UpdateCamera(&_camera);
// }

// void Raylib::drawText(const std::string &text, Vector2 pos, float scale, Color color)
// {
//     DrawText(text.c_str(), pos.x, pos.y, scale, color);
// }

// void Raylib::drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, Color color)
// {
//     DrawTextEx(font, text.c_str(), {pos.x, pos.y}, scale, 10, color);
// }

// void Raylib::drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, float spacing, Color color)
// {
//     DrawTextEx(font, text.c_str(), {pos.x, pos.y}, scale, spacing, color);
// }

// Vector2 Raylib::measureTextEx(Font font, std::string text, int scale) const
// {
//     return MeasureTextEx(font, text.c_str(), scale, 10);
// };

// Vector2 Raylib::measureTextEx(Font font, std::string text, int scale, int spacing) const
// {
//     return MeasureTextEx(font, text.c_str(), scale, spacing);
// };

// void Raylib::drawFps(const Vector2 &pos)
// {
//     DrawFPS(pos.x, pos.y);
// }

// void Raylib::drawTexture(Texture2D texture, Vector2 position)
// {
//     DrawTexture(texture, position.x, position.y, WHITE);
// }

// void Raylib::drawModel(Model model, Vector3 position)
// {
//     DrawModel(model, position, 1, WHITE);
// }

// void Raylib::drawCubeTexture(Texture2D texture, Vector3 position)
// {
//     DrawCubeTexture(texture, position, 0.5, 1, 0.5, WHITE);
// }

// void Raylib::drawRectangleRec(Rectangle &rec, Color color)
// {
//     DrawRectangleRec(rec, color);
// }

// Font Raylib::getDefaultFont() const
// {
//     return GetFontDefault();
// }

// char Raylib::getPressedCharacter() const
// {
//     return GetCharPressed();
// }

// int Raylib::getKeyPressed() const
// {
//     return GetKeyPressed();
// }

// bool Raylib::isKeyPressed(int button) const
// {
//     return IsKeyPressed(button);
// }

// bool Raylib::isKeyReleased(int button) const
// {
//     return IsKeyReleased(button);
// }

// bool Raylib::isKeyDown(int button) const
// {
//     return IsKeyDown(button);
// }

// bool Raylib::isMousePressed() const
// {
//     return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
// }

// bool Raylib::isMouseDown() const
// {
//     return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
// }

// bool Raylib::isMouseReleased() const
// {
//     return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
// }

// bool Raylib::checkCollisionPointRec(Rectangle &rec, const Vector2 &point) const
// {
//     return CheckCollisionPointRec(point, rec);
// }

// Vector2 Raylib::getMousePosition() const
// {
//     return GetMousePosition();
// }

// Image Raylib::loadImage(std::string fileName) const
// {
//     return LoadImage(fileName.c_str());
// }

// Texture2D Raylib::loadTexture(const std::string path)
// {
//     Image image = LoadImage(path.c_str());
//     Vector2 windowSize = getScreenSize();
//     ImageResize(&image, windowSize.x, windowSize.y);
//     Texture2D texture = LoadTextureFromImage(image);
//     UnloadImage(image);
//     return texture;
// }

// Texture2D Raylib::loadTextureFromImage(Image image)
// {
//     return LoadTextureFromImage(image);
// }

// Mesh Raylib::genMeshCubicmap(Image image, Vector3 cubeSize)
// {
//     return GenMeshCubicmap(image, cubeSize);
// }

// Model Raylib::loadModelFromMesh(Mesh mesh, Texture2D mapTexture)
// {
//     Model model = LoadModelFromMesh(mesh);
//     model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = mapTexture;
//     return model;
// }

// std::vector<Color> Raylib::loadImageColors(Image image)
// {
//     std::vector<Color> colors;
//     Color *color_array = LoadImageColors(image);

//     for (int i = 0; i < image.width * image.height; i++) {
//         colors.push_back(color_array[i]);
//     }
//     UnloadImageColors(color_array);
//     return colors;
// }

// void Raylib::unloadImage(Image image)
// {
//     UnloadImage(image);
// }

// void Raylib::unloadTexture(Texture2D texture)
// {
//     UnloadTexture(texture);
// }

// void Raylib::unloadModel(Model model)
// {
//     UnloadModel(model);
// }