/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** ImageColors
*/

#pragma once
#include "Image.hpp"
#include <vector>


namespace Raylib {
    class ImageColors {
        public:
            ImageColors(Raylib::Image image);
            ~ImageColors();
            std::vector<Color> getColors() const;
        private:
            std::vector<Color> _colors;
    };
}