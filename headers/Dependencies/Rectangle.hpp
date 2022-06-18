/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Rectangle
*/

#pragma once

#include "raylib.h"

namespace Raylib {
    class Rectangle {
        public:
            Rectangle(Vector2 position, Vector2 size);
            ~Rectangle();
            bool isCollisionWithRec(Vector2 position, Vector2 size);
        protected:
        private:
            ::Rectangle _rectangle;
    };
};