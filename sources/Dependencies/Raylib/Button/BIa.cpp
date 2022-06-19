/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BIa
*/

#include "BIa.hpp"
#include "raylib.h"

Indie::Scenes::BIa::BIa(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(game, state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BIa::BIa(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(game, state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BIa::run()
{
    _btnAction = true;
    _isIa = !_isIa;
    if (_isIa)
        _text.setText("Ia: ON");
    else
        _text.setText("Ia: OFF");
}

bool Indie::Scenes::BIa::getIsIa()
{
    return _isIa;
}