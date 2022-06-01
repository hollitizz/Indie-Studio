/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SMenu
*/

#include <iostream>
#include "SMenu.hpp"

Indie::Scenes::SMenu::SMenu(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SMenu init" << std::endl;
}

Indie::Scenes::SMenu::~SMenu()
{}

void Indie::Scenes::SMenu::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _Raylib.closeWindow();
        std::cout << "Exit Game" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_G)) {
        _State.setScene(Indie::Scenes::Game);
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "SGame" << std::endl;
    }
}
