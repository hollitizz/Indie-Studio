/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SMenu
*/

#include <iostream>
#include <memory>
#include "SMenu.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SMenu::SMenu(Raylib &raylib, Indie::State &state) : AScene(raylib, state)
{
    std::cout << "SMenu init" << std::endl;

    _backgroundTexture = _Raylib.loadTexture("assets/Menu/menu_background.png");
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BPlay>(
            raylib,
            state,
            Vector2{200, 100},
            Vector2{100, 100},
            "Play",
            50,
            _Raylib.getDefaultFont())
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BExit>(
            raylib,
            Vector2{200, 100},
            Vector2{100, 250},
            "Exit",
            50,
            _Raylib.getDefaultFont()
        )
    );
}

Indie::Scenes::SMenu::~SMenu()
{
    _Raylib.unloadTexture(_backgroundTexture);
    std::cout << "SMenu destructor" << std::endl;
}

void Indie::Scenes::SMenu::event()
{
    for (auto &button : _buttons) {
        button->event();
    }
    if (_Raylib.isKeyPressed(KEY_ESCAPE)) {
        _Raylib.closeWindow();
        std::cout << "Exit Game" << std::endl;
    }
    if (_Raylib.isKeyPressed('G')) {
        _State.setScene(Indie::Scenes::Game);
        _State.setGameScene(Indie::Scenes::Hud);
        std::cout << "SGame" << std::endl;
    }
}

void Indie::Scenes::SMenu::displayBackground()
{
    DrawTexture(_backgroundTexture, 0, 0, WHITE);
}

void Indie::Scenes::SMenu::displayButtons()
{
    for (auto &button : _buttons) {
        button->display();
    }
}

void Indie::Scenes::SMenu::displayTexts()
{
    Vector2 windowSize = _Raylib.getScreenSize();
    Vector2 textSize;
    std::string text;
    Font font = _Raylib.getDefaultFont();
    int fontSize = 0;

    text = "IndieStudio";
    fontSize = windowSize.x / 27.5;
    textSize = _Raylib.measureTextEx(_Raylib.getDefaultFont(), text.c_str(), fontSize);
    _Raylib.drawTextEx(
        font, text,
        {windowSize.x / 2 - textSize.x / 2, windowSize.y / 4 - textSize.y / 2},
        fontSize, BLACK
    );
    text = "Bomberman";
    fontSize = windowSize.x / 38.4;
    textSize = _Raylib.measureTextEx(_Raylib.getDefaultFont(), text.c_str(), fontSize);
    _Raylib.drawTextEx(
        font, text,
        {windowSize.x / 2 - textSize.x / 2, windowSize.y / 4 + textSize.y / 2},
        fontSize, BLACK
    );
}

void Indie::Scenes::SMenu::display() {
    DrawScope _(_Raylib);
    displayBackground();
    displayButtons();
    displayTexts();
}
