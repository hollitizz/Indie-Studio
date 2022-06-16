/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SHud
*/

#pragma once

#include "AScene.hpp"

#include "State.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SHud : public AScene {
            public:
                SHud(Indie::Game &game, Indie::State state);
                ~SHud();
                void event() {};
                void display() override;
            private:
        };
    };
};