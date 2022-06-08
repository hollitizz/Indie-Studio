/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Bomberman
*/

#include "Bomberman.hpp"
#include "SMenu.hpp"
#include "SGame.hpp"

Indie::Bomberman::Bomberman()
{
    _Raylib.createWindow(1920, 1080, "Bomberman", 60);
    _Raylib.setCamera({0, 30, 8}, {0, 4, 0}, {0, 1, 0}, 35, 0);
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(_Raylib, _State);
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(_Raylib, _State);
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    while (_Raylib.isOpen()) {
        _scenes[_State.getScene()]->event();
        if (!_Raylib.isOpen())
            break;
        _scenes[_State.getScene()]->display();
    }
}