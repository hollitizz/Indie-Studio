/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SMenu
*/

#include <iostream>
#include "SMenu.hpp"
#include "DrawScope.hpp"

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

void Indie::Scenes::SMenu::display() {
    DrawScope _(_Raylib);
    Vector2 screenSize = _Raylib.getScreenSize();
    Vector2 textSize;
    std::string text;
    Font font = _Raylib.getDefaultFont();

    text = "IndieStudio";
    textSize = _Raylib.measureTextEx(GetFontDefault(), text.c_str(), 70);
    _Raylib.drawTextEx(
        font, text,
        {screenSize.x / 2 - textSize.x / 2, screenSize.y / 4 - textSize.y / 2},
        70, BLACK
    );
    text = "Bomberman";
    textSize = _Raylib.measureTextEx(GetFontDefault(), text.c_str(), 50);
    _Raylib.drawTextEx(
        font, text,
        {screenSize.x / 2 - textSize.x / 2, screenSize.y / 4 + textSize.y / 2},
        50, BLACK
    );
}
