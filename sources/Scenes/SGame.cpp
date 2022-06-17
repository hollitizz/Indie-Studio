/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SGame
*/

#include <iostream>
#include "SGame.hpp"
#include "SInit.hpp"
#include "SHud.hpp"
#include "SPause.hpp"
#include "SSettings.hpp"
#include "SOver.hpp"
#include "DrawScope.hpp"
#include "raylib.h"
#include <array>

Indie::Scenes::SGame::SGame(Indie::Game &game, State &state):
    AScene(game, state), _Blur(game, {0, 0}, {0, 0}, {151, 154, 154, 70})
{
    std::cerr << "SGame init" << std::endl;
    _State.setGameScene(Indie::Scenes::Init);
    _scenes[Indie::Scenes::Init] = std::make_shared<Indie::Scenes::SInit>(game, _State);
    _scenes[Indie::Scenes::Hud] = std::make_shared<Indie::Scenes::SHud>(game, _State);
    _scenes[Indie::Scenes::Pause] = std::make_shared<Indie::Scenes::SPause>(game, _State);
    _scenes[Indie::Scenes::Settings] = std::make_shared<Indie::Scenes::SSettings>(game, _State);
    _scenes[Indie::Scenes::Over] = std::make_shared<Indie::Scenes::SOver>(game, _State);
}

Indie::Scenes::SGame::~SGame()
{}

void Indie::Scenes::SGame::playerEvents()
{
    int bombsToPop;
    for (auto &Player : _Game.getPlayers()) {
        if (!Player->getIsAlive())
            continue;
        bombsToPop = 0;
        for (size_t i = 0; i < Player->getBombsLen(); i++) {
            auto bomb = Player->getBomb(i);
            if (bomb->getShouldVanished()) {
                bombsToPop++;
                continue;
            }
            if (bomb->getIsExploded()) {
                _Game.killEntities(bomb->getExplosionsPos());
            }
        }
        for (int j = 0; j < bombsToPop; ++j)
            Player->popBomb();
        if (Player->getIsAlive())
            Player->move();
    }
}

void Indie::Scenes::SGame::event()
{
    if (_State.getGameScene() != Hud) {
        _scenes[_State.getGameScene()]->event();
        return;
    }
    if (_State.getGameScene() != Over && _Game.getNbAlivePlayers() <= 1) {
        if (_Game.getNbAlivePlayers() == 0)
            _State.setWinner("aucun");
        else {
            _State.setWinner(_Game.getNames()[_Game.getLastPlayer()]->getText());
            _Game.getPlayers()[_Game.getLastPlayer()]->setAnimation(ANIMATIONS[IDLE]);
        }
        _State.setGameScene(Over);
        return;
    }
    playerEvents();
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Pause);
        for (auto &Player : _Game.getPlayers())
            Player->pauseBombs();
        std::cerr << "Pause" << std::endl;
    }
}

void Indie::Scenes::SGame::diplay3DScope()
{
    Raylib::Draw3DScope _(_Game.getWindow().getCamera());

    _Game.getMap().display();
    for (auto &Player : _Game.getPlayers())
        Player->display();
}

void Indie::Scenes::SGame::display()
{
    Raylib::DrawScope _;

    DrawText("SGame", 10, 10, 20, BLACK);
    diplay3DScope();
    if (_State.getGameScene() != Indie::Scenes::Init && _State.getGameScene() != Indie::Scenes::Hud)
        _Blur.display();
    _scenes[_State.getGameScene()]->display();
    DrawFPS(10, 50);
}