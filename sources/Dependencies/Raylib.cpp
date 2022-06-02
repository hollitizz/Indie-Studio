/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Raylib
*/

#include <iostream>
#include "Raylib.hpp"

Raylib::Raylib()
{}

Raylib::~Raylib()
{}

void Raylib::createWindow(int width, int height, std::string title, size_t fps)
{
    _screenSize.first = width;
    _screenSize.second = height;
    InitWindow(_screenSize.first, _screenSize.second, title.c_str());
    SetTargetFPS(fps);
    SetExitKey(KEY_NULL);
}

void Raylib::closeWindow()
{
    CloseWindow();
}

Vector2 Raylib::getScreenSize() const
{
    return {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };
}


bool Raylib::isOpen()
{
    return !WindowShouldClose();
}


void Raylib::beginDrawing()
{
    BeginDrawing();
};

void Raylib::clearBackground()
{
    ClearBackground(WHITE);
};

void Raylib::clearBackground(Color color)
{
    ClearBackground(color);
};

void Raylib::endDrawing()
{
    EndDrawing();
};

void Raylib::setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
}

Camera Raylib::getCamera() const
{
    return _camera;
}

void Raylib::drawText(const std::string &text, Vector2 pos, float scale, Color color)
{
    DrawText(text.c_str(), pos.x, pos.y, scale, color);
}

void Raylib::drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, Color color)
{
    DrawTextEx(font, text.c_str(), {pos.x, pos.y}, scale, 10, color);
}

void Raylib::drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, float spacing, Color color)
{
    DrawTextEx(font, text.c_str(), {pos.x, pos.y}, scale, spacing, color);
}

Vector2 Raylib::measureTextEx(Font font, std::string text, int scale) const
{
    return MeasureTextEx(font, text.c_str(), scale, 10);
};

Vector2 Raylib::measureTextEx(Font font, std::string text, int scale, int spacing) const
{
    return MeasureTextEx(font, text.c_str(), scale, spacing);
};

void Raylib::drawFps(const Vector2 &pos)
{
    DrawFPS(pos.x, pos.y);
}

void Raylib::drawTexture(Texture2D texture, Vector2 position)
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

void Raylib::drawRectangleRec(Rectangle &rec, Color color)
{
    DrawRectangleRec(rec, color);
}

Font Raylib::getDefaultFont() const
{
    return GetFontDefault();
}

char Raylib::getPressedCharacter() const
{
    return GetCharPressed();
}

int Raylib::getKeyPressed() const
{
    return GetKeyPressed();
}

bool Raylib::isKeyPressed(int button) const
{
    return IsKeyPressed(button);
}

bool Raylib::isKeyReleased(int button) const
{
    return IsKeyReleased(button);
}

bool Raylib::isMousePressed() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool Raylib::isMouseDown() const
{
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Raylib::isMouseReleased() const
{
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Raylib::checkCollisionPointRec(Rectangle &rec, const Vector2 &point) const
{
    return CheckCollisionPointRec(point, rec);
}

Vector2 Raylib::getMousePosition() const
{
    return GetMousePosition();
}

Texture2D Raylib::loadTexture(const std::string path)
{
    Image image = LoadImage(path.c_str());
    Vector2 windowSize = getScreenSize();
    ImageResize(&image, windowSize.x, windowSize.y);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    return texture;
}

void Raylib::unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}