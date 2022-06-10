/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Camera
*/

#include "Camera.hpp"

Raylib::Camera::Camera(Vector3 position, Vector3 target, Vector3 up, float fov, float aspectRatio):
    _camera(::Camera{position, target, up, fov, aspectRatio})
{
}

Raylib::Camera::~Camera()
{
}

void Raylib::Camera::update()
{
    UpdateCamera(&_camera);
}

::Camera Raylib::Camera::getCamera() const
{
    return _camera;
}