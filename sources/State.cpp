/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** State
*/

#include "State.hpp"

Indie::State::State()
{
    _winner = "aucun";
    _sceneCurrent = Indie::Scenes::Menu;
}

void Indie::State::setWinner(std::string winner)
{
    _winner = winner;
}

void Indie::State::setScene(Indie::Scenes::Type scene)
{
    _sceneCurrent = scene;
}

void Indie::State::setGameScene(Indie::Scenes::Type scene)
{
    _sceneGameCurrent = scene;
}

std::string Indie::State::getWinner() const
{
    return _winner;
}

Indie::Scenes::Type Indie::State::getScene() const
{
    return _sceneCurrent;
}

Indie::Scenes::Type Indie::State::getGameScene() const
{
    return _sceneGameCurrent;
}

bool Indie::State::IsGamePaused() const
{
    return _sceneGameCurrent != Indie::Scenes::Hud;
}