/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SMenu
*/

#include <iostream>
#include <memory>
#include "raylib.h"
#include "BInit.hpp"
#include "BExit.hpp"
#include "SMenu.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SMenu::SMenu(Indie::Game &game, Indie::State &state) : AScene(game, state),
    _backgroundTexture("assets/Menu/menu_background.png"),
    _indieStudio("Indie Studio", BLACK),
    _bomberman("Bomberman", BLACK)
{
    Vector2 windowSize = _Game.getWindowSize();
    std::cerr << "SMenu init" << std::endl;

    _buttons.push_back(
        std::make_shared<Indie::Scenes::BInit>(
            state,
            Vector2{300, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Play",
            50,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BExit>(
            state,
            Vector2{300, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 + 30},
            "Exit",
            50,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
}

Indie::Scenes::SMenu::~SMenu()
{
}

void Indie::Scenes::SMenu::event()
{
    for (auto &button : _buttons) {
        button->event();
        if (button->getBtnAction())
            break;
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        std::cerr << "Exit Game" << std::endl;
    }
    if (IsKeyPressed(KEY_G)) {
        _State.setScene(Indie::Scenes::Game);
        _State.setGameScene(Indie::Scenes::Hud);
        std::cerr << "SGame" << std::endl;
    }
}

void Indie::Scenes::SMenu::displayBackground()
{
    _backgroundTexture.draw(Vector2{0, 0});
}

void Indie::Scenes::SMenu::displayButtons()
{
    for (auto &button : _buttons) {
        button->display();
    }
}

void Indie::Scenes::SMenu::displayTexts()
{
    Vector2 windowSize = _Game.getWindowSize();
    _indieStudio.setPosition({windowSize.x / 2 - _indieStudio.getSize().x / 2,
            windowSize.y / 4 - _indieStudio.getSize().y / 2},
        windowSize.x / 27.5
    );
    _bomberman.setPosition({windowSize.x / 2 - _bomberman.getSize().x / 2,
            windowSize.y / 4 + _bomberman.getSize().y / 2},
        windowSize.x / 38.4
    );
    _indieStudio.draw();
    _bomberman.draw();
}

void Indie::Scenes::SMenu::display() {
    Raylib::DrawScope _;

    displayBackground();
    displayButtons();
    displayTexts();
}
