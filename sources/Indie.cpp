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
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>(&_Raylib);
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>(&_Raylib);
    _sceneCurrent = Indie::Scenes::Type::Menu;
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    _Raylib.createWindow(1920, 1080, "Bomberman", 60);
    while (_Raylib.isOpen()) {
        if (_Raylib.isKeyPressed(KEY_G)) {
            _sceneCurrent = Indie::Scenes::Game;
            _scenes[_sceneCurrent]->test();
        }
        _scenes[_sceneCurrent]->start();
        _scenes[_sceneCurrent]->display();
        _scenes[_sceneCurrent]->stop();
    }
}

Indie::Scenes::AScene::AScene(Raylib *raylib)
{
    _Raylib = raylib;
}

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
    _Raylib->drawFps({10, 10});
}

Indie::Scenes::SMenu::SMenu(Raylib *raylib) : AScene(raylib)
{
    std::cout << "SMenu init" << std::endl;
}

Indie::Scenes::SMenu::~SMenu()
{}

void Indie::Scenes::SMenu::test()
{
    std::cout << "SMenu" << std::endl;
}

Indie::Scenes::SGame::SGame(Raylib *raylib) : AScene(raylib)
{
    std::cout << "SMenu init" << std::endl;
}

Indie::Scenes::SGame::~SGame()
{}

void Indie::Scenes::SGame::test()
{
    std::cout << "SGame" << std::endl;
}
