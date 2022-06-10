/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Game
*/

#pragma once

#include <memory>
#include "Raylib.hpp"
#include "APlayer.hpp"
#include "Map.hpp"

namespace Indie
{
    class Game {
        public:
            Game(Raylib &raylib);
            ~Game();

        protected:
            Raylib &_Raylib;
        private:
            Vector2 _mapDeplacement = {9, 0};
            Vector3 _mapPosition = { -16 + _mapDeplacement.x, 0, -8 + _mapDeplacement.y };
            Indie::GameComponents::Map _Map;
            std::vector<std::shared_ptr<Indie::GameComponents::APlayer>> _Players;
    };
}
