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

    // Vector2 windowSize = _Raylib.getScreenSize();
    // ImageResize(&_backgroundImage, windowSize.x, windowSize.y);
    // _backgroundTexture = LoadTextureFromImage(_backgroundImage);

}

Indie::Scenes::SMenu::~SMenu()
{
    std::cout << "SMenu destructor" << std::endl;
}

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

void Indie::Scenes::SMenu::displayBackground()
{
    // Image background = LoadImage("assets/Menu/menu_background.png");
    // Texture2D tBackground = LoadTextureFromImage(background);
    // DrawTexture(tBackground, 0, 0, WHITE);
    // UnloadImage(background);
    // UnloadTexture(tBackground);
    // TODO: init background in a constructor
}

void Indie::Scenes::SMenu::displayButtons()
{

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
    textSize = _Raylib.measureTextEx(GetFontDefault(), text.c_str(), fontSize);
    _Raylib.drawTextEx(
        font, text,
        {windowSize.x / 2 - textSize.x / 2, windowSize.y / 4 - textSize.y / 2},
        70, BLACK
    );
    text = "Bomberman";
    fontSize = windowSize.x / 38.4;
    textSize = _Raylib.measureTextEx(GetFontDefault(), text.c_str(), 50);
    _Raylib.drawTextEx(
        font, text,
        {windowSize.x / 2 - textSize.x / 2, windowSize.y / 4 + textSize.y / 2},
        50, BLACK
    );
}

void Indie::Scenes::SMenu::display() {
    DrawScope _(_Raylib);
    displayBackground();
    displayButtons();
    displayTexts();
}
