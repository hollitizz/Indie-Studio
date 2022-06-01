/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SSettings
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
        class SSettings : public AScene {
            public:
                SSettings(Raylib &raylib, Indie::State &state);
                ~SSettings();
                void event() override;
            private:
        };
    }
}
