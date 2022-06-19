/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** AScene
*/

#include "AScene.hpp"
#include "raylib.h"

Indie::Scenes::AScene::AScene(Indie::Game &game, Indie::State &state):
    _State(state), _Game(game)
{}

void Indie::Scenes::AScene::eventAll()
{
    _Game.getMusicMenu().update();
}
