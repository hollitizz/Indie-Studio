/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SGame
*/

#pragma once

#include <map>
#include <memory>
#include "AScene.hpp"
#include "Raylib.hpp"
#include "State.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SGame : public AScene {
            public:
                SGame(Raylib &raylib, State &state);
                ~SGame();
                void event() override;
                void display() override;
            private:
                std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
        };
    }
}
