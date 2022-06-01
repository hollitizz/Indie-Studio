/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SOver
*/

#include <iostream>
#include "SOver.hpp"

Indie::Scenes::SOver::SOver(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SOver init" << std::endl;
}

Indie::Scenes::SOver::~SOver()
{}

void Indie::Scenes::SOver::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {}
}

void Indie::Scenes::SOver::display()
{
    _Raylib.drawText("SOver", {10, 25}, 20, BLACK);
}