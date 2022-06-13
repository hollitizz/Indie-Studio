/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Image
*/

#include "Image.hpp"
#include <iostream>

Raylib::Image::Image(std::string path)
{
    std::cerr << "Image Init" << std::endl;
    _image = LoadImage(path.c_str());
}

Raylib::Image::~Image()
{
    std::cerr << "Image Destroy" << std::endl;
    UnloadImage(_image);
}

const ::Image Raylib::Image::getImage() const
{
    return _image;
}