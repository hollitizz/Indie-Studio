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
#include "Map.hpp"
#include "Human.hpp"

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
                // TODO: reset() fct when the game is over
            private:
                Vector2 _mapDeplacement = {9, 0};
                Vector3 _mapPosition = { -16 + _mapDeplacement.x, 0, -8 + _mapDeplacement.y };
                Indie::Game::Map _Map;
                void diplay3DScope();
                std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
                std::vector<std::shared_ptr<Indie::Game::APlayer>> _Players;
        };
    }
}
