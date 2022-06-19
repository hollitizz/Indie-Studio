/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Cube
*/

#pragma once

#include "Texture2D.hpp"

namespace Raylib {
    class Cube {
        public:
            Cube(Vector3 position, Vector3 size);
            ~Cube() = default;
            void draw(Color color) const;
            void draw(Raylib::Texture2D &texture) const;
            Vector3 getPosition() const;
            void drawAt(Vector3 position, Vector3 size, Color color) const;
            void drawAt(Vector3 position, Vector3 size, Raylib::Texture2D texture) const;
        private:
            Vector3 _position;
            Vector3 _size;
    };
};