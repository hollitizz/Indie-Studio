/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Window
*/

#include "Window.hpp"
#include <iostream>

Raylib::Window::Window(Vector2 size, std::string title, size_t fps,
    Vector3 position, Vector3 target, Vector3 up, float fov, int aspectRatio):
    _camera(position, target, up, fov, aspectRatio)
{
    std::cerr << "Window Init" << std::endl;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(size.x, size.y, title.c_str());
    InitAudioDevice();
    SetWindowMinSize(1300, 800);
    SetTargetFPS(fps);
    SetExitKey(KEY_NULL);
}

Raylib::Window::~Window()
{
    StopSoundMulti();
    CloseAudioDevice();
    std::cerr << "Window Destroy" << std::endl;
}

Vector2 Raylib::Window::getSize() const
{
    return {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };
}

Raylib::Camera &Raylib::Window::getCamera()
{
    return _camera;
}

void Raylib::Window::close() const
{
    CloseWindow();
}

bool Raylib::Window::isOpen() const
{
    return !WindowShouldClose();
}