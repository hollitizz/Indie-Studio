/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Cube
*/

#pragma once

#include "raylib.h"

namespace Raylib {
    class Cube {
        public:
            Cube(Vector3 position, Vector3 size);
            Cube(const Cube&) = delete;
            ~Cube() = default;
            void draw(Color) const;
            void drawAt(Vector3 position, Vector3 size, Color color) const;
        private:
            Vector3 _position;
            Vector3 _size;
    };
};