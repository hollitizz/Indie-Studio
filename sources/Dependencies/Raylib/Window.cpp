/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Window
*/

#include "Window.hpp"

Raylib::Window::Window(Vector2 size, std::string title, size_t fps,
    Vector3 position, Vector3 target, Vector3 up, float fov, float aspectRatio):
    _camera(Raylib::Camera(position, target, up, fov, aspectRatio))
{
    InitWindow(size.x, size.y, title.c_str());
    SetTargetFPS(fps);
    SetExitKey(KEY_NULL);
}

Raylib::Window::~Window()
{}

Vector2 Raylib::Window::getSize() const
{
    return {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };
}

void Raylib::Window::closeWindow()
{
    CloseWindow()
}

bool Raylib::Window::isOpen() const
{
    return !WindowShouldClose();
}
