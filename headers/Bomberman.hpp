/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Bomberman
*/

#pragma once

#include <map>
#include <memory>
#include "IScene.hpp"
#include "Window.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace Indie
{
    class Bomberman {
        public:
            Bomberman();
            ~Bomberman();
            void loop();
        private:
            std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
            Indie::Game _Game;
            State _State;
    };
};
