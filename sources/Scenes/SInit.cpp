/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#include <iostream>
#include "BRemove.hpp"
#include "BAdd.hpp"
#include "BPlay.hpp"
#include "SInit.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SInit::SInit(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    Vector2 windowSize = _Game.getWindowSize();

    _buttons.push_back(
        std::make_shared<Indie::Scenes::BRemove>(
            game,
            state,
            Vector2{300, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Remove",
            50,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BAdd>(
            game,
            state,
            Vector2{300, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 + 30},
            "Add",
            50,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BPlay>(
            state,
            Vector2{300, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 + 110},
            "Play",
            50,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    std::cerr << "SInit init" << std::endl;
}

Indie::Scenes::SInit::~SInit()
{}

void Indie::Scenes::SInit::event()
{
    for (auto &button : _buttons) {
        button->event();
        if (button->getBtnAction())
            break;
    }
    if (IsKeyPressed(KEY_Q)) {
        _Game.getWindow().close();
        std::cerr << "Exit" << std::endl;
    }
}

void Indie::Scenes::SInit::displayButtons()
{
    for (auto &button : _buttons) {
        button->display();
    }
}

void Indie::Scenes::SInit::display()
{
    DrawText("SInit", 10, 25, 20, BLACK);
    displayButtons();
}