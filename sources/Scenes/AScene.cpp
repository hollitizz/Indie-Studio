/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** AScene
*/

#include "AScene.hpp"

Indie::Scenes::AScene::AScene(Raylib &raylib, Indie::State &state) : _Raylib(raylib), _State(state)
{}

void Indie::Scenes::AScene::start()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Indie::Scenes::AScene::stop()
{
    EndDrawing();
}

void Indie::Scenes::AScene::display()
{
    _Raylib.drawFps({10, 10});
}
