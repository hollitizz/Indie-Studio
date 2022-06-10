/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#include "Game.hpp"
#include "gameConst.hpp"

Indie::Game::Game():
    _window(Raylib::Window({1920, 1080}, "Bomberman", 60,
        { 0, 30, 8 }, { 0, 4, 0 }, { 0, 1, 0 }, 35, 0)),
    _map(Indie::GameComponents::Map(raylib, _mapPosition))
{
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i) {
        _players.push_back(std::make_shared<Indie::GameComponent::Human>(
            _Map,
            PLAYER_STARTS_POSITION[i],
            PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png"
        ));
    }
}

Indie::Game::~Game()
{
}

Indie::Game::getWindow() const
{
    return _window;
}

Indie::Game::getMap() const
{
    return _map;
}

Indie::Game::getPlayers() const
{
    return _players;
}