/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#pragma once

#include "BIa.hpp"
#include "Slider.hpp"
#include "Choice.hpp"
#include "Input.hpp"
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
                std::vector<std::shared_ptr<Input>> _input;
                std::vector<std::shared_ptr<BIa>> _ia;
                Choice _choice;
                Slider _slider;
                Raylib::Text _nbPlayers;
        };
    }
}
