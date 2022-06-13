/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BPlay
*/

#include "BPlay.hpp"

Indie::Scenes::BPlay::BPlay(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BPlay::BPlay(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BPlay::run()
{
    _btnAction = true;
    _State.setScene(Indie::Scenes::Game);
    _State.setGameScene(Indie::Scenes::Hud);
    std::cerr << "SGame" << std::endl;
}