/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SOver
*/

#include <iostream>
#include "SOver.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SOver::SOver(Indie::Game &game, Indie::State &state) :
    AScene(game, state), _over("Game Over", BLACK, 50)
{
    std::cerr << "SOver init" << std::endl;
}

Indie::Scenes::SOver::~SOver()
{}

void Indie::Scenes::SOver::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {}
}

void Indie::Scenes::SOver::displayTexts()
{
    Vector2 windowSize = _Game.getWindowSize();

    if (_State.getWinner() == "aucun")
        _over.setText("Aucun gagnant, égalité");
    else
        _over.setText("Gagnant " + _State.getWinner());
    _over.setPosition({windowSize.x / 2 - _over.getSize().x / 2,
            windowSize.y / 4 - _over.getSize().y / 2}
    );
    _over.draw();
}

void Indie::Scenes::SOver::display()
{
    // DrawText("SOver", 10, 25, 20, BLACK);
    displayTexts();
}