/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SHud
*/

#include <iostream>
#include "SHud.hpp"

Indie::Scenes::SHud::SHud(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SHud init" << std::endl;
}

Indie::Scenes::SHud::~SHud()
{}

void Indie::Scenes::SHud::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cout << "Pause" << std::endl;
    }
}
