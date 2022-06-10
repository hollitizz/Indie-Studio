/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Texture2D
*/

#pragma once

#include "raylib.h"
#include "Image.hpp"
#include <string>

namespace Raylib {
    class Texture2D {
        public:
            Texture2D(std::string path);
            Texture2D(Raylib::Image image);
            ~Texture2D();
            ::Texture2D getTexture() const;
            void draw(Vector2 position) const;
        protected:
        private:
            ::Texture2D _texture;
    };
}
