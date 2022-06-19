/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Blur
*/

#include <iostream>
#include "Blur.hpp"
#include "raylib.h"

Indie::Scenes::Blur::Blur(Indie::Game &game, Vector2 size, Vector2 position, Color color = {WHITE}):
    _blur({position.x, position.y, size.x, size.y}), _game(game), _color(color)
{}

void Indie::Scenes::Blur::display()
{
    _blur.width = _game.getWindowSize().x;
    _blur.height = _game.getWindowSize().y;
    DrawRectangleRec(_blur, _color);
}