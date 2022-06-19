/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BRestart
*/

#include "BRestart.hpp"

Indie::Scenes::BRestart::BRestart(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(game, state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BRestart::BRestart(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(game, state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BRestart::run()
{
    _btnAction = true;
    _Game.getMusicMenu().setMusic("assets/Musics/game.mp3");
    _Game.getMap().genMapBlocks();
    _Game.preLoadGame();
    _Game.loadGame();
    _State.setScene(Indie::Scenes::Game);
    _State.setGameScene(Indie::Scenes::Hud);
    std::cerr << "SGame" << std::endl;
}