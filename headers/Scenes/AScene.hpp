/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** AScene
*/

#pragma once

#include "IScene.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class AScene : public IScene {
            public:
                AScene(Indie::Game &game, Indie::State &state);
                ~AScene() = default;
                virtual void eventAll();
                virtual void event() = 0;
            protected:
                virtual void display() = 0;
                State &_State;
                Indie::Game &_Game;
        };
    }
}
