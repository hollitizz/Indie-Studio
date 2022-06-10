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
#include "State.hpp"
#include "Game.hpp"

namespace Indie
{
    class State;
    namespace Scenes
    {
        class SGame : public AScene {
            public:
                SGame(Indie::Game game, State state);
                ~SGame();
                void event() override;
                void display() override;
                // TODO: reset() fct when the game is over
            private:
                void diplay3DScope();
                std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
        };
    }
}
