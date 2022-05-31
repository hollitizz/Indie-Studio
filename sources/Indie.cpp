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
    _scenes[Indie::Scenes::Type::Menu] = std::make_shared<Indie::Scenes::SMenu>();
    _scenes[Indie::Scenes::Type::Game] = std::make_shared<Indie::Scenes::SGame>();
    _sceneCurrent = Indie::Scenes::Type::Menu;
}

Indie::Bomberman::~Bomberman()
{}

void Indie::Bomberman::loop()
{
    _scenes[_sceneCurrent]->display();
    _scenes[_sceneCurrent]->test();
    _sceneCurrent = Indie::Scenes::Game;
    _scenes[_sceneCurrent]->display();
    _scenes[_sceneCurrent]->test();
}

void Indie::Scenes::AScene::display()
{
    std::cout << "all scene" << std::endl;
}

Indie::Scenes::SMenu::SMenu()
{}

Indie::Scenes::SMenu::~SMenu()
{}

void Indie::Scenes::SMenu::test()
{
    std::cout << "SMenu" << std::endl;
}

Indie::Scenes::SGame::SGame()
{}

Indie::Scenes::SGame::~SGame()
{}

void Indie::Scenes::SGame::test()
{
    std::cout << "SGame" << std::endl;
}
