/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#pragma once

#include "Button.hpp"
#include "AScene.hpp"
#include "State.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SInit : public AScene {
            public:
                SInit(Indie::Game &game, Indie::State &state);
                ~SInit();
                void event() override;
                void display() override;
                void displayButtons();
                void displayTexts();
            private:
                std::vector<std::shared_ptr<Button>> _buttons;
                Raylib::Text _nbPlayers;
        };
    }
}
