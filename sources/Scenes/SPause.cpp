/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SPause
*/

#include <iostream>
#include "SPause.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SPause::SPause(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SPause init" << std::endl;
}

Indie::Scenes::SPause::~SPause()
{}

void Indie::Scenes::SPause::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "Hud" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_S)) {
        _State.setGameScene(Indie::Scenes::Settings);
        std::cout << "Settings" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_Q)) {
        _Raylib.closeWindow();
        std::cout << "Exit" << std::endl;
    }
}

void Indie::Scenes::SPause::display()
{
    _Raylib.drawText("SPause", {10, 25}, 20, BLACK);
}