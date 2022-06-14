/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SGame
*/

#include <iostream>
#include "SGame.hpp"
#include "SHud.hpp"
#include "SPause.hpp"
#include "SSettings.hpp"
#include "SOver.hpp"
#include "DrawScope.hpp"
#include "Const.hpp"
#include "raylib.h"
#include <array>

Indie::Scenes::SGame::SGame(Indie::Game &game, State &state):
    AScene(game, state)
{
    std::cerr << "SGame init" << std::endl;
    _State.setGameScene(Indie::Scenes::Hud);
    _scenes[Indie::Scenes::Hud] = std::make_shared<Indie::Scenes::SHud>(game, _State);
    _scenes[Indie::Scenes::Pause] = std::make_shared<Indie::Scenes::SPause>(game, _State);
    _scenes[Indie::Scenes::Settings] = std::make_shared<Indie::Scenes::SSettings>(game, _State);
    _scenes[Indie::Scenes::Over] = std::make_shared<Indie::Scenes::SOver>(game, _State);

}

Indie::Scenes::SGame::~SGame()
{}

void Indie::Scenes::SGame::event()
{
    if (_State.getGameScene() != Hud) {
        _scenes[_State.getGameScene()]->event();
        return;
    }
    size_t i;
    int bombsToPop;
    for (auto &Player : _Game.getPlayers()) {
        bombsToPop = 0;
        for (i = 0; i < Player->getBombsLen(); i++) {
            auto bomb = Player->getBomb(i);
            if (bomb->getShouldVanished()) {
                bombsToPop++;
                continue;
            }
            // if (bomb->getIsExploded())
                // exploseWall(bomb);
        }
        for (int j = 0; j < bombsToPop; ++j)
            Player->popBomb();
        if (Player->getIsAlive())
            Player->move();
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cerr << "Pause" << std::endl;
    }
}

void Indie::Scenes::SGame::diplay3DScope()
{
    Raylib::Draw3DScope _(_Game.getWindow().getCamera());

    _Game.getMap().display();
    for (auto &Player : _Game.getPlayers())
        if (Player->getIsAlive())
            Player->display();
}

void Indie::Scenes::SGame::display()
{
    Raylib::DrawScope _;

    DrawText("SGame", 10, 10, 20, BLACK);
    diplay3DScope();
    _scenes[_State.getGameScene()]->display();
    DrawFPS(10, 50);
}