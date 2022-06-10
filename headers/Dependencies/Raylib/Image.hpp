/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Image
*/

#pragma once

#include "raylib.h"
#include <string>

namespace Raylib {
    class Image {
        public:
            Image(std::string path);
            ~Image();
            ::Image getImage() const;
        protected:
        private:
            ::Image _image;
    };
};