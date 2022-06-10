/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Window
*/

#pragma once

#include "Camera.hpp"
#include <string>

namespace Raylib {
    class Window {
        public:
            Window(Vector2 size, std::string title, size_t fps,
            Vector3 position, Vector3 target, Vector3 up, float fov, float aspectRatio
            );
            ~Window();
            bool isOpen() const;
            void closeWindow();
            Vector2 getSize() const;
        private:
            Raylib::Camera _camera;
    };
};