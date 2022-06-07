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
#include "gameConst.hpp"
#include <array>

Indie::Scenes::SGame::SGame(Raylib &raylib, Indie::State &state) :
    AScene(raylib, state), _Map(Indie::Game::Map(raylib, _mapPosition))
{
    std::cout << "SGame init" << std::endl;
    _State.setGameScene(Indie::Scenes::Hud);
    _scenes[Indie::Scenes::Hud] = std::make_shared<Indie::Scenes::SHud>(_Raylib, _State);
    _scenes[Indie::Scenes::Pause] = std::make_shared<Indie::Scenes::SPause>(_Raylib, _State);
    _scenes[Indie::Scenes::Settings] = std::make_shared<Indie::Scenes::SSettings>(_Raylib, _State);
    _scenes[Indie::Scenes::Over] = std::make_shared<Indie::Scenes::SOver>(_Raylib, _State);
    for (int i = 0; i < PLAYER_STARTS_POSITION.size(); ++i) {
        _Players.push_back(std::make_shared<Indie::Game::Human>(
            _Raylib,
            _Map,
            PLAYER_STARTS_POSITION[i],
            PLAYER_KEY_MAP[i],
            "assets/Game/Player/textures/player1.png"
        ));
    }
}

Indie::Scenes::SGame::~SGame()
{
}

void Indie::Scenes::SGame::event()
{
    if (_State.getIsGamePaused()) {
        _scenes[_State.getGameScene()]->event();
        return;
    }
    for (auto &Player : _Players) {
        if (Player->getIsAlive())
            Player->move();
    }
    // if (_Raylib.isKeyPressed(KEY_M)) {
    //     _State.setScene(Indie::Scenes::Menu);
    //     std::cout << "SMenu" << std::endl;
    // }
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Pause);
        _State.setIsGamePaused(true);
        std::cout << "Pause" << std::endl;
    }
}

void Indie::Scenes::SGame::diplay3DScope()
{
    Draw3DScope _(_Raylib);

    _Map.display();
    for (auto &Player : _Players)
        if (Player->getIsAlive())
            Player->display();
}


void Indie::Scenes::SGame::display()
{
    DrawScope _(_Raylib);

    _Raylib.drawText("SGame", {10, 10}, 20, BLACK);
    diplay3DScope();
    // _scenes[_State.getGameScene()]->display();
    _Raylib.drawFps({10, 30});
}