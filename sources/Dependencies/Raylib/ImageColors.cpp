/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** ImageColors
*/

#include "ImageColors.hpp"
#include <iostream>

Raylib::ImageColors::ImageColors(const Raylib::Image &image)
{
    std::cerr << "ImageColor Init" << std::endl;
    Color *color_array = LoadImageColors(image.getImage());

    for (int i = 0; i < image.getImage().width * image.getImage().height; i++) {
        _colors.push_back(color_array[i]);
    }
    UnloadImageColors(color_array);
}

Raylib::ImageColors::~ImageColors()
{
    std::cerr << "ImageColor Destroy" << std::endl;
}

std::vector<Color> Raylib::ImageColors::getColors() const
{
    return _colors;
}
