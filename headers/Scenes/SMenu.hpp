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
        };
    }
}
