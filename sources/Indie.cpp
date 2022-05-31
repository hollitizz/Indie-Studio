/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Indie
*/

#include <iostream>
#include "Indie.hpp"

Indie::Bomberman::Bomberman()
{
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(_Raylib, _State);
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(_Raylib, _State);
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    _Raylib.createWindow(1920, 1080, "Bomberman", 60);
    while (_Raylib.isOpen()) {
        _scenes[_State.getScene()]->event();
        if (!_Raylib.isOpen())
            break;
        _scenes[_State.getScene()]->start();
        _scenes[_State.getScene()]->display();
        _scenes[_State.getScene()]->stop();
    }
}

Indie::Scenes::AScene::AScene(Raylib &raylib, Indie::State &state) : _Raylib(raylib), _State(state)
{}

void Indie::Scenes::AScene::start()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Indie::Scenes::AScene::stop()
{
    EndDrawing();
}

void Indie::Scenes::AScene::display()
{
    _Raylib.drawFps({10, 10});
}

Indie::Scenes::SMenu::SMenu(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SMenu init" << std::endl;
}

Indie::Scenes::SMenu::~SMenu()
{}

void Indie::Scenes::SMenu::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _Raylib.closeWindow();
        std::cout << "Exit Game" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_G)) {
        _State.setScene(Indie::Scenes::Game);
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "SGame" << std::endl;
    }
}

Indie::Scenes::SHud::SHud(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SHud init" << std::endl;
}

Indie::Scenes::SHud::~SHud()
{}

void Indie::Scenes::SHud::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cout << "Pause" << std::endl;
    }
}

Indie::Scenes::SPause::SPause(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SPause init" << std::endl;
}

Indie::Scenes::SPause::~SPause()
{}

void Indie::Scenes::SPause::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "Hud" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_S)) {
        _State.setGameScene(Indie::Scenes::Settings);
        std::cout << "Settings" << std::endl;
    }
}

Indie::Scenes::SSettings::SSettings(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SSettings init" << std::endl;
}

Indie::Scenes::SSettings::~SSettings()
{}

void Indie::Scenes::SSettings::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "Hud" << std::endl;
    }
    if (_Raylib.isKeyPressed(KEY_B)) {
        _State.setGameScene(Indie::Scenes::Pause);
        std::cout << "Pause" << std::endl;
    }
}

Indie::Scenes::SOver::SOver(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SOver init" << std::endl;
}

Indie::Scenes::SOver::~SOver()
{}

void Indie::Scenes::SOver::event()
{
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {}
}

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

Indie::State::State()
{
    _sceneCurrent = Indie::Scenes::Menu;
}

void Indie::State::setScene(Indie::Scenes::Type scene)
{
    _sceneCurrent = scene;
}

void Indie::State::setGameScene(Indie::Scenes::Type scene)
{
    _sceneGameCurrent = scene;
}

Indie::Scenes::Type Indie::State::getScene() const
{
    return _sceneCurrent;
}

Indie::Scenes::Type Indie::State::getGameScene() const
{
    return _sceneGameCurrent;
}
