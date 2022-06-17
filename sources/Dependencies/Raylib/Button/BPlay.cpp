/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BPlay
*/

#include "BPlay.hpp"

Indie::Scenes::BPlay::BPlay(std::vector<std::shared_ptr<Input>> &input, Choice &choice, Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(game, state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture),
    _input(input), _choice(choice)
{
}

Indie::Scenes::BPlay::BPlay(std::vector<std::shared_ptr<Input>> &input, Choice &choice, Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(game, state, size, position, text, fontSize, font, color),
    _input(input), _choice(choice)
{
}

void Indie::Scenes::BPlay::run()
{
    _btnAction = true;
    // _Game.setNbAlivePlayers(_Game.getNbPlayers());
    for (size_t i = 0; i < _Game.getNbPlayers(); i++)
        _Game.getNames()[i]->setText(_input[i]->getText());
    _Game.loadGame();
    _State.setScene(Indie::Scenes::Game);
    _State.setGameScene(Indie::Scenes::Hud);
    std::cerr << "SGame" << std::endl;
}