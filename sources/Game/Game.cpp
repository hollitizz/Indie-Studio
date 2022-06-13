/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#include "Game.hpp"
#include "Const.hpp"

Indie::Game::Game():
    _window({1920, 1080}, "Bomberman", 60,
        { 0, 30, 8 }, { 0, 4, 0 }, { 0, 1, 0 }, 35, 0),
    _map(_mapPosition)
{
    std::cerr << "Game Init" << std::endl;
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i) {
        _players.push_back(std::make_shared<Indie::GameComponents::Human>(
            _map,
            PLAYER_STARTS_POSITION[i],
            PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png"
        ));
    }
}

Indie::Game::~Game()
{
    std::cerr << "Game Destroy" << std::endl;
}

const Raylib::Window &Indie::Game::getWindow() const
{
    return _window;
}

Vector2 Indie::Game::getWindowSize() const
{
    return _window.getSize();
}

const Indie::GameComponents::Map &Indie::Game::getMap() const
{
    return _map;
}

std::vector<std::shared_ptr<Indie::GameComponents::APlayer>> Indie::Game::getPlayers() const
{
    return _players;
}