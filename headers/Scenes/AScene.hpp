/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** AScene
*/

#pragma once

#include "IScene.hpp"
#include "Raylib.hpp"
#include "State.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class AScene : public IScene {
            public:
                AScene(Raylib &raylib, State &state);
                ~AScene() = default;
                virtual void start();
                virtual void stop();
                virtual void display();
                virtual void event() = 0;
            protected:
                Raylib &_Raylib;
                State &_State;
        };
    }
}
