/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#include "BRemove.hpp"
#include "BAdd.hpp"
#include "BPlay.hpp"
#include "SInit.hpp"
#include "DrawScope.hpp"
#include <iostream>

Indie::Scenes::SInit::SInit(Indie::Game &game, Indie::State &state) : AScene(game, state),
    _nbPlayers("", BLACK, 30),
    _choice({"Player 1", " Player 2", "Player 3", "Player 4"},
            game,
            state,
            Vector2{225, 60},
            Vector2{0, 0},
            30,
            GetFontDefault(),
            ChoiceColor{BLUE, ORANGE, RED})
{
    Vector2 windowSize = _Game.getWindowSize();

    _buttons.push_back(
        std::make_shared<Indie::Scenes::BRemove>(
            game,
            state,
            Vector2{225, 60},
            Vector2{windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 - 50},
            "Remove",
            30,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BAdd>(
            game,
            state,
            Vector2{225, 60},
            Vector2{windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 + 30},
            "Add",
            30,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );
    _buttons.push_back(
        std::make_shared<Indie::Scenes::BPlay>(
            _input,
            _choice,
            game,
            state,
            Vector2{225, 60},
            Vector2{windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 + 110},
            "Play",
            30,
            GetFontDefault(),
            ButtonColor{BLUE, ORANGE, RED}
        )
    );

    for (size_t i = 0; i < 4; ++i)
        _input.push_back(std::make_shared<Indie::Scenes::Input>("player " + std::to_string(i + 1), Vector2{300, 60}, Vector2{windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 + i * 110}));
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
    _choice.event();
    _input[_choice.getChoice()]->event();
}

void Indie::Scenes::SInit::displayButtons()
{
    Vector2 windowSize = _Game.getWindowSize();

    for (int i = 0 ; i < _buttons.size() ; i++) {
        _buttons[i]->setPosition({windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - 225 / 2), windowSize.y / 2 + (i - 1) * 110});
        _buttons[i]->display();
    }
    _choice.setPosition({(windowSize.x / 8 - 225 / 2), windowSize.y / 2 - 220});
    _choice.display();
    _input[_choice.getChoice()]->setPosition({(windowSize.x / 8 - 225 / 2), windowSize.y / 2 - 110});
    _input[_choice.getChoice()]->display();
}

void Indie::Scenes::SInit::displayTexts()
{
    Vector2 windowSize = _Game.getWindowSize();

    _nbPlayers.setText("Players: " + std::to_string(_Game.getNbPlayers()));
    _nbPlayers.setPosition({windowSize.x - windowSize.x / 4 + (windowSize.x / 8 - _nbPlayers.getSize().x / 2), windowSize.y / 2 - 200});
    _nbPlayers.draw();
}

void Indie::Scenes::SInit::display()
{
    DrawText("SInit", 10, 25, 20, BLACK);
    displayButtons();
    displayTexts();
}