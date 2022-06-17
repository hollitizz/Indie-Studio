/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#include "Game.hpp"
#include "Const.hpp"
#include <cmath>

Indie::Game::Game():
    _window({1600, 900}, "Bomberman", 60,
        { 0, 30, 8 }, { 0, 4, 0 }, { 0, 1, 0 }, 35, 0),
    _map(_mapPosition), _explosion({0, 0, 0}, {0, 0, 0})
{
    std::cerr << "Game Init" << std::endl;
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i) {
        _players.push_back(std::make_shared<Indie::GameComponents::Human>(
            _map,
            PLAYER_STARTS_POSITION[i],
            PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png",
            "assets/Game/Player/models/playerModel.iqm",
            COLORS[i],
            ANIMATIONS[IDLE]
        ));
        _names.push_back(std::make_shared<Raylib::Text>(
            "",
            COLORS[i],
            20
        ));
    }
}

Indie::Game::~Game()
{
    std::cerr << "Game Destroy" << std::endl;
}

void Indie::Game::killEntities(std::vector<Vector3> explodedPoints)
{
    Vector3 position;

    _map.cleanExplodedBoxes(explodedPoints);
    for (auto &player : _players) {
        if (!player->getIsAlive())
            continue;
        position = player->getPosition();
        for (auto &explodedPoint : explodedPoints) {
            if ((std::ceil(position.x) == explodedPoint.x && std::ceil(position.z) == explodedPoint.z) ||
                (std::floor(position.x) == explodedPoint.x && std::floor(position.z) == explodedPoint.z) ||
                (std::floor(position.x) == explodedPoint.x && std::ceil(position.z) == explodedPoint.z) ||
                (std::ceil(position.x) == explodedPoint.x && std::floor(position.z) == explodedPoint.z)) {
                std::cerr << "Player killed" << std::endl;
                player->setIsAlive(false);
                _nbAlivePlayers--;
                break;
            }
        }
    }
}

Raylib::Window &Indie::Game::getWindow()
{
    return _window;
}

Vector2 Indie::Game::getWindowSize() const
{
    return _window.getSize();
}

Indie::GameComponents::Map &Indie::Game::getMap()
{
    return _map;
}

std::vector<std::shared_ptr<Indie::GameComponents::APlayer>> Indie::Game::getPlayers() const
{
    return _players;
}

std::vector<std::shared_ptr<Raylib::Text>> Indie::Game::getNames() const
{
    return _names;
}

void Indie::Game::rmPlayer()
{
    for (size_t i = _players.size() - 1; i > 1; --i)
        if (_players[i]->getIsAlive()) {
            _players[i]->setIsAlive(false);
            _nbPlayers--;
            std::cerr << "Remove Player" << std::endl;
            break;
        }
}

void Indie::Game::addPlayer()
{
    for (size_t i = _players.size() - 1; i > 1; --i)
        if (!_players[i]->getIsAlive()) {
            _players[i]->setIsAlive(true);
            _nbPlayers++;
            std::cerr << "Add Player" << std::endl;
            break;
        }
}

const int Indie::Game::getNbPlayers() const
{
    return _nbPlayers;
}

void Indie::Game::setNbAlivePlayers(int nb)
{
    _nbAlivePlayers = nb;
}

const size_t Indie::Game::getLastPlayer() const
{
    for (size_t i = 0; i < _nbPlayers; ++i)
        if (_players[i]->getIsAlive())
            return i;
    return 0;
}

const int Indie::Game::getNbAlivePlayers() const
{
    return _nbAlivePlayers;
}