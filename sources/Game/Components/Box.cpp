/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Box
*/

#include "Box.hpp"

Indie::GameComponents::Box::Box(Vector3 position, Raylib::Texture2D &texture):
    _box(position, {1, 1, 1}), _texture(texture)
{}

void Indie::GameComponents::Box::draw() const
{
    _box.draw(_texture);
}

Vector3 Indie::GameComponents::Box::getPosition() const
{
    return _box.getPosition();
}

