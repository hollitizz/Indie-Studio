/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Image
*/

#include "Image.hpp"

Raylib::Image::Image(std::string path)
{
    _image = LoadImage(path.c_str());
}

Raylib::Image::~Image()
{
    UnloadImage(_image);
}

::Image Raylib::Image::getImage() const
{
    return _image;
}