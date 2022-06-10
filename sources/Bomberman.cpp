/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Bomberman
*/

#include "Bomberman.hpp"
#include "SMenu.hpp"
#include "SGame.hpp"

Indie::Bomberman::Bomberman():
    _Game(Indie::Game())
{
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(
        std::reference_wrapper<Indie::State>(_State)
    );
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(
        std::reference_wrapper<Indie::Game>(_Game), std::reference_wrapper<Indie::State>(_State)
    );
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    Raylib::Window window = _Game.getWindow();

    while (window.isOpen()) {
        _scenes[_State.getScene()]->event();
        if (!window.isOpen())
            break;
        _scenes[_State.getScene()]->display();
    }
}