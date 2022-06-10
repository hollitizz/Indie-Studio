/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SPause
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
        class SPause : public AScene {
            public:
                SPause(Raylib &raylib, Indie::State &state);
                ~SPause();
                void event() override;
                void display() override;
            private:
        };
    }
}
