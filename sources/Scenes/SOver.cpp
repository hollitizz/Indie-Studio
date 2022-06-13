/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SOver
*/

#include <iostream>
#include "SOver.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SOver::SOver(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    std::cerr << "SOver init" << std::endl;
}

Indie::Scenes::SOver::~SOver()
{}

void Indie::Scenes::SOver::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {}
}

void Indie::Scenes::SOver::display()
{
    DrawText("SOver", 10, 25, 20, BLACK);
}