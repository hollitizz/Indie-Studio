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

Indie::Scenes::SGame::SGame(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SGame init" << std::endl;
    _State.setGameScene(Indie::Scenes::Hud);
    _scenes[Indie::Scenes::Hud] = std::make_shared<Indie::Scenes::SHud>(_Raylib, _State);
    _scenes[Indie::Scenes::Pause] = std::make_shared<Indie::Scenes::SPause>(_Raylib, _State);
    _scenes[Indie::Scenes::Settings] = std::make_shared<Indie::Scenes::SSettings>(_Raylib, _State);
    _scenes[Indie::Scenes::Over] = std::make_shared<Indie::Scenes::SOver>(_Raylib, _State);
}

Indie::Scenes::SGame::~SGame()
{}

void Indie::Scenes::SGame::event()
{
    if (_Raylib.isKeyPressed(KEY_M)) {
        _State.setScene(Indie::Scenes::Menu);
        std::cout << "SMenu" << std::endl;
    }
    _scenes[_State.getGameScene()]->event();
}

void Indie::Scenes::SGame::display()
{
    _Raylib.drawText("SGame", {10, 10}, 20, BLACK);
    _scenes[_State.getGameScene()]->display();
}