/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Camera
*/

#pragma once

#include "raylib.h"

namespace Raylib {
    class Camera {
        public:
            Camera(Vector3 position, Vector3 target, Vector3 up, float fov, int aspectRatio);
            Camera(const Camera&) = delete;
            ~Camera();
            void update();
            ::Camera getCamera() const;
        protected:
        private:
            ::Camera _camera;
    };
}
