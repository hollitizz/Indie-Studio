/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SSettings
*/

#include <iostream>
#include "SSettings.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SSettings::SSettings(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    std::cerr << "SSettings init" << std::endl;
}

Indie::Scenes::SSettings::~SSettings()
{}

void Indie::Scenes::SSettings::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        _State.setIsGamePaused(false);
        std::cerr << "Hud" << std::endl;
    }
    if (IsKeyPressed(KEY_B)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cerr << "Pause" << std::endl;
    }
    if (IsKeyPressed(KEY_Q)) {
        _Game.getWindow().close();
        std::cerr << "Exit" << std::endl;
    }
}

void Indie::Scenes::SSettings::display()
{
    DrawText("SSettings", 10, 25, 20, BLACK);
}