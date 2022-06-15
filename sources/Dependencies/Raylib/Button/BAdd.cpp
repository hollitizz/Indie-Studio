/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BAdd
*/

#include "BAdd.hpp"

Indie::Scenes::BAdd::BAdd(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture),
    _game(game)
{
}

Indie::Scenes::BAdd::BAdd(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(state, size, position, text, fontSize, font, color),
    _game(game)
{
}

void Indie::Scenes::BAdd::run()
{
    _btnAction = true;
    _game.addPlayer();
}