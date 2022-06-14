/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SOver
*/

#pragma once

#include "AScene.hpp"
#include "State.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SOver : public AScene {
            public:
                SOver(Indie::Game &game, Indie::State &state);
                ~SOver();
                void event() override;
                void display() override;
            private:
        };
    }
}
