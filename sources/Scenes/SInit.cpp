/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#include <iostream>
#include "SInit.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SInit::SInit(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    std::cerr << "SInit init" << std::endl;
}

Indie::Scenes::SInit::~SInit()
{}

void Indie::Scenes::SInit::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
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

void Indie::Scenes::SInit::display()
{
    DrawText("SInit", 10, 25, 20, BLACK);
}