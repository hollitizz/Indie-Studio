/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SSettings
*/

#include <iostream>
#include "SSettings.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SSettings::SSettings(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SSettings init" << std::endl;
}

Indie::Scenes::SSettings::~SSettings()
{}

void Indie::Scenes::SSettings::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "Hud" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_B)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cout << "Pause" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_Q)) {
        _Raylib.closeWindow();
        std::cout << "Exit" << std::endl;
    }
}

void Indie::Scenes::SSettings::display()
{
    _Raylib.drawText("SSettings", {10, 25}, 20, BLACK);
}