/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Game
*/

#include "Game.hpp"
#include "Human.hpp"
#include "Const.hpp"

Indie::Game::Game(Raylib &raylib) : _Raylib(raylib), _Map(Indie::GameComponents::Map(raylib, _mapPosition))
{
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i)
        _Players.push_back(std::make_shared<Indie::GameComponents::Human>(_Raylib, _Map,
            PLAYER_STARTS_POSITION[i], PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png"));
}

Indie::Game::~Game()
{}
