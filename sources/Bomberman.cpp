/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Bomberman
*/

#include "Bomberman.hpp"
#include "SMenu.hpp"
#include "SGame.hpp"
#include "Game.hpp"

Indie::Bomberman::Bomberman()
{
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(_Game, _State);
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(_Game, _State);
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    const Raylib::Window &window = _Game.getWindow();

    while (window.isOpen()) {
        _scenes[_State.getScene()]->event();
        if (!window.isOpen())
            break;
        _scenes[_State.getScene()]->display();
    }
}