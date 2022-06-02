/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SMenu
*/

#pragma once

#include "AScene.hpp"
#include "Raylib.hpp"
#include "State.hpp"
#include "BExit.hpp"
#include "BPlay.hpp"
#include <vector>

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SMenu : public AScene {
            public:
                SMenu(Raylib &raylib, State &state);
                ~SMenu();
                void event() override;
                void display() override;
            private:
                void displayBackground();
                void displayButtons();
                void displayTexts();
                Texture2D _backgroundTexture;
                std::vector<std::shared_ptr<Button>> _buttons;
        };
    }
}
