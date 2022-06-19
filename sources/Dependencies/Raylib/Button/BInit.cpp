/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BInit
*/

#include "BInit.hpp"

Indie::Scenes::BInit::BInit(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(game, state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BInit::BInit(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(game, state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BInit::run()
{
    _btnAction = true;
    _Game.preLoadGame();
    _State.setScene(Indie::Scenes::Game);
    _State.setGameScene(Indie::Scenes::Init);
    std::cerr << "SGame" << std::endl;
}