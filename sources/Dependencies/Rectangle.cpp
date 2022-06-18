/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Raylib::Rectangle::Rectangle(Vector2 position, Vector2 size)
{
    _rectangle.x = position.x;
    _rectangle.y = position.y;
    _rectangle.width = size.x;
    _rectangle.height = size.y;
}

Raylib::Rectangle::~Rectangle()
{}

bool Raylib::Rectangle::isCollisionWithRec(Vector2 position, Vector2 size)
{
    return CheckCollisionRecs(_rectangle, {position.x, position.y, size.x, size.y});
}