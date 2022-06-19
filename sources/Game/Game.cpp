/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#include "Game.hpp"
#include "Rectangle.hpp"
#include <cmath>

Indie::Game::Game():
    _window({1600, 900}, "Bomberman", 60,
        { 0, 30, 8 }, { 0, 4, 0 }, { 0, 1, 0 }, 35, 0),
    _map(_mapPosition), _explosion({0, 0, 0}, {0, 0, 0}),
    _soundBomb("assets/Sounds/bomb.wav"),
    _musicMenu("assets/Musics/menu.mp3")
{
    std::cerr << "Game Init" << std::endl;
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i) {
        _players.push_back(std::make_shared<Indie::GameComponents::Human>(
            _map,
            _soundBomb,
            Vector2{PLAYER_STARTS_POSITION[i].x - 0.25f, PLAYER_STARTS_POSITION[i].y - 0.25f},
            PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png",
            "assets/Game/Player/models/playerModel.iqm",
            COLORS[i],
            ANIMATIONS[IDLE],
            "assets/Game/Player/models/bomb.iqm",
            "assets/Game/Player/models/bombAnimation.iqm",
            "assets/Game/Player/models/bombExplosion.obj"
        ));
        _names.push_back(std::make_shared<Raylib::Text>(
            "",
            COLORS[i],
            20
        ));
    }
    _musicMenu.start();
}

Indie::Game::~Game()
{
    std::cerr << "Game Destroy" << std::endl;
}

void Indie::Game::preLoadGame()
{
    for (size_t i = 0; i < _nbPlayers; ++i) {
        _players[i]->setPosition(Vector2{PLAYER_STARTS_POSITION[i].x - 0.25f, PLAYER_STARTS_POSITION[i].y - 0.25f});
        _players[i]->setIsAlive(true);
        _players[i]->setAnimation(ANIMATIONS[IDLE]);
        _players[i]->clearBonuses();
    }
    _map.remMapBlocks();
}

void Indie::Game::loadGame()
{
    _nbAlivePlayers = _nbPlayers;
    _map.genMapBlocks();
}

void Indie::Game::killEntities(std::vector<Vector3> explodedPoints)
{
    Raylib::Rectangle playerHitBox({0, 0}, {0.5, 0.5});

    _map.cleanExplodedBoxes(explodedPoints);
    for (auto &player : _players) {
        if (!player->getIsAlive())
            continue;
        playerHitBox.setPosition({player->getPosition().x, player->getPosition().z});
        for (auto &explodedPoint : explodedPoints) {
                if (playerHitBox.isCollisionWithRec(
                        {explodedPoint.x - 0.5f, explodedPoint.z - 0.5f}, {1, 1}
                    )) {
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

Raylib::Sound &Indie::Game::getSoundBomb()
{
    return _soundBomb;
}

Raylib::Music &Indie::Game::getMusicMenu()
{
    return _musicMenu;
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