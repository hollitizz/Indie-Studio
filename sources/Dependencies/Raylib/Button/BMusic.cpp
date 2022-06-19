/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BMusic
*/

#include "BMusic.hpp"
#include "raylib.h"

Indie::Scenes::BMusic::BMusic(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(game, state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BMusic::BMusic(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(game, state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BMusic::run()
{
    _btnAction = true;
    if (_Game.getMusicMenu().getMuted()) {
        _Game.getMusicMenu().start();
        _text.setText("Music: ON");
    } else {
        _Game.getMusicMenu().stop();
        _text.setText("Music: OFF");
    }
}