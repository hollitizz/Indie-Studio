/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SSettings
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
        class SSettings : public AScene {
            public:
                SSettings(Indie::Game &game, Indie::State &state);
                ~SSettings();
                void event() override;
                void display() override;
                void displayButtons();
            private:
                std::vector<std::shared_ptr<Button>> _buttons;
        };
    }
}
