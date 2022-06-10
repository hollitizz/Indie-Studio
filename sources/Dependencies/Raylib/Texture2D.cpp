/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Texture2D
*/

#include "Texture2D.hpp"

Raylib::Texture2D::Texture2D(std::string path)
{
    _texture = LoadTexture(path.c_str());
}

Raylib::Texture2D::Texture2D(Raylib::Image image)
{
    _texture = LoadTextureFromImage(image.getImage());
}

Raylib::Texture2D::~Texture2D()
{
    UnloadTexture(_texture);
}

::Texture2D Raylib::Texture2D::getTexture() const
{
    return _texture;
}

void Raylib::Texture2D::draw(Vector2 position) const
{
    DrawTexture(_texture, position.x, position.y, WHITE);
}