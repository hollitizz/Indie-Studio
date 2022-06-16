/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SOver
*/

#include <iostream>
#include "SOver.hpp"
#include "BInit.hpp"
#include "BExit.hpp"
#include "DrawScope.hpp"

Indie::Scenes::SOver::SOver(Indie::Game &game, Indie::State &state) :
    AScene(game, state), _over("Game Over", BLACK, 50)
{
    Vector2 windowSize = _Game.getWindowSize();
    std::cerr << "SOver init" << std::endl;

    _buttons.push_back(
        std::make_shared<Indie::Scenes::BInit>(
            game,
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
            game,
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

Indie::Scenes::SOver::~SOver()
{}

void Indie::Scenes::SOver::event()
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
}

void Indie::Scenes::SOver::displayButtons()
{
    Vector2 windowSize = _Game.getWindowSize();

    for (size_t i = 0 ; i < _buttons.size() ; i++) {
        _buttons[i]->setPosition({windowSize.x / 2 - 150, windowSize.y / 2 + i * 100});
        _buttons[i]->display();
    }
}

void Indie::Scenes::SOver::displayTexts()
{
    Vector2 windowSize = _Game.getWindowSize();

    if (_State.getWinner() == "aucun")
        _over.setText("Aucun gagnant, égalité");
    else
        _over.setText("Gagnant " + _State.getWinner());
    _over.setPosition({windowSize.x / 2 - _over.getSize().x / 2,
            windowSize.y / 4 - _over.getSize().y / 2}
    );
    _over.draw();
}

void Indie::Scenes::SOver::display()
{
    // DrawText("SOver", 10, 25, 20, BLACK);
    displayButtons();
    displayTexts();
}