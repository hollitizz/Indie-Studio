/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** State
*/

#include "State.hpp"

Indie::State::State()
{
    _sceneCurrent = Indie::Scenes::Menu;
}

void Indie::State::setScene(Indie::Scenes::Type scene)
{
    _sceneCurrent = scene;
}

void Indie::State::setGameScene(Indie::Scenes::Type scene)
{
    _sceneGameCurrent = scene;
}

Indie::Scenes::Type Indie::State::getScene() const
{
    return _sceneCurrent;
}

Indie::Scenes::Type Indie::State::getGameScene() const
{
    return _sceneGameCurrent;
}
