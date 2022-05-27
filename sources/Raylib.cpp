/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Raylib
*/

#include "Raylib.hpp"

Raylib::Raylib()
{}

Raylib::~Raylib()
{
    CloseWindow();
}

void Raylib::createWindow(int width, int height, std::string title, size_t fps)
{
    _screenSize.first = width;
    _screenSize.second = height;
    InitWindow(_screenSize.first, _screenSize.second, title.c_str());
    SetTargetFPS(fps);
}

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

void Raylib::drawFps(const Vector2 &pos)
{
    DrawFPS(pos.x, pos.y);
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

Vector2 Raylib::getMousePosition() const
{
    return GetMousePosition();
}
