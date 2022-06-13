/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>

Raylib::Camera::Camera(Vector3 position, Vector3 target, Vector3 up, float fov, int aspectRatio)
{
    _camera = ::Camera{position, target, up, fov, aspectRatio};
    std::cerr << "Camera Init" << std::endl;
}

Raylib::Camera::~Camera()
{
    std::cerr << "Camera Destroy" << std::endl;
}

void Raylib::Camera::update()
{
    UpdateCamera(&_camera);
}

::Camera Raylib::Camera::getCamera() const
{
    return _camera;
}