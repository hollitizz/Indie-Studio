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
#include <cstdlib>
#include <ctime>

Indie::Bomberman::Bomberman():
    _Game()
{
    std::srand(std::time(nullptr));
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(_Game, _State);
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(_Game, _State);
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    Raylib::Window &window = _Game.getWindow();

    SetCameraMode(window.getCamera().getCamera(), CAMERA_FREE);
    while (window.isOpen()) {
        window.getCamera().update();
        _scenes[_State.getScene()]->event();
        if (!window.isOpen())
            break;
        _scenes[_State.getScene()]->display();
        _scenes[_State.getScene()]->eventAll();
    }
}