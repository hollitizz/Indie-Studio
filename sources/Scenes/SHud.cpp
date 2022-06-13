/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SHud
*/

#include <iostream>
#include "SHud.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SHud::SHud(Indie::Game &game, Indie::State state): AScene(game, state)
{
    std::cerr << "SHud init" << std::endl;
}

Indie::Scenes::SHud::~SHud()
{}

void Indie::Scenes::SHud::display()
{
    DrawText("SHud", 10, 25, 20, BLACK);
}