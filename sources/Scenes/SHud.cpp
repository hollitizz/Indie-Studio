/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SHud
*/

#include <iostream>
#include "SHud.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SHud::SHud(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SHud init" << std::endl;
}

Indie::Scenes::SHud::~SHud()
{}

void Indie::Scenes::SHud::display()
{
    _Raylib.drawText("SHud", {10, 25}, 20, BLACK);
}