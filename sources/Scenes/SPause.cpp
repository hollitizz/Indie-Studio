/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SPause
*/

#include <iostream>
#include "SPause.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SPause::SPause(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    std::cerr << "SPause init" << std::endl;
}

Indie::Scenes::SPause::~SPause()
{}

void Indie::Scenes::SPause::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cerr << "Hud" << std::endl;
    }
    if (IsKeyPressed(KEY_S)) {
        _State.setGameScene(Indie::Scenes::Settings);
        std::cerr << "Settings" << std::endl;
    }
    if (IsKeyPressed(KEY_A)) {
        CloseWindow();
        std::cerr << "Exit" << std::endl;
    }
}

void Indie::Scenes::SPause::display()
{
    DrawText("SPause", 10, 25, 20, BLACK);
}