/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SInit
*/

#pragma once

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
            private:
        };
    }
}
