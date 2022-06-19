/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SSettings
*/

#include <iostream>
#include "BResume.hpp"
#include "BRestart.hpp"
#include "BExit.hpp"
#include "BMusic.hpp"
#include "BSound.hpp"
#include "SSettings.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SSettings::SSettings(Indie::Game &game, Indie::State &state) : AScene(game, state)
{
    Vector2 windowSize = _Game.getWindowSize();
    std::cerr << "SSettings init" << std::endl;

    _buttons.push_back(
        std::make_shared<Indie::Scenes::BResume>(
            game,
            state,
            Vector2{350, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Resume",
            45,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BRestart>(
            game,
            state,
            Vector2{350, 70},
            Vector2{windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 + 110},
            "Replay",
            45,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BSound>(
            game,
            state,
            Vector2{350, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Sound: ON",
            45,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BMusic>(
            game,
            state,
            Vector2{350, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Music: ON",
            45,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BExit>(
            game,
            state,
            Vector2{350, 70},
            Vector2{windowSize.x / 2 - 150, windowSize.y / 2 - 50},
            "Exit",
            45,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
}

Indie::Scenes::SSettings::~SSettings()
{}

void Indie::Scenes::SSettings::event()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        _State.setGameScene(Indie::Scenes::Hud);
        std::cerr << "Hud" << std::endl;
        for (auto &Player : _Game.getPlayers())
            Player->resumeBombs();
    }
    if (IsKeyPressed(KEY_Q)) {
        _Game.getWindow().close();
        std::cerr << "Exit" << std::endl;
    }
    for (auto &button : _buttons) {
        button->event();
        if (button->getBtnAction())
            break;
    }
}

void Indie::Scenes::SSettings::displayButtons()
{
    Vector2 windowSize = _Game.getWindowSize();

    for (int i = 0 ; i < _buttons.size() ; i++) {
        _buttons[i]->setPosition({windowSize.x / 2 - 150, windowSize.y / 2 + (i - 2) * 100});
        _buttons[i]->display();
    }
}

void Indie::Scenes::SSettings::display()
{
    DrawText("SSettings", 10, 25, 20, BLACK);
    displayButtons();
}