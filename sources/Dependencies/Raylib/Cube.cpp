/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Cube
*/

#include "Cube.hpp"

Raylib::Cube::Cube(Vector3 position, Vector3 size):
    _position(position),
    _size(size)
{
}

void Raylib::Cube::draw(Color color) const
{
    DrawCube(_position, _size.x, _size.y, _size.z, color);
}