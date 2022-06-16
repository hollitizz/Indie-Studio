/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SHud
*/

#include <iostream>
#include "SHud.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SHud::SHud(Indie::Game &game, Indie::State state): AScene(game, state)
{
    std::cerr << "SHud init" << std::endl;
}

Indie::Scenes::SHud::~SHud()
{}

void Indie::Scenes::SHud::display()
{
    Vector2 windowSize = _Game.getWindowSize();
    int count = 0;

    DrawText("SHud", 10, 25, 20, BLACK);
    for (int i = 0; i < _Game.getNbPlayers(); ++i)
        if (_Game.getPlayers()[i]->getIsAlive()) {
            _Game.getNames()[i]->setPosition({10, windowSize.y / 2 + (count++ - _Game.getNbAlivePlayers() / 2) * 25});
            _Game.getNames()[i]->draw();
        }
}