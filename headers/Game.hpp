/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#pragma once
#include "Window.hpp"
#include "Map.hpp"
#include "Human.hpp"
#include <vector>
#include <memory>

namespace Indie {
    class Game {
        public:
            Game();
            Game(const Game&) = delete;
            ~Game();
            const Raylib::Window &getWindow() const;
            Vector2 getWindowSize() const;
            const Indie::GameComponents::Map &getMap() const;
            std::vector<std::shared_ptr<Indie::GameComponents::APlayer>> getPlayers() const;
        private:
            Vector2 _mapDeplacement = {9, 0};
            Vector3 _mapPosition = { -16 + _mapDeplacement.x, 0, -8 + _mapDeplacement.y };
            Raylib::Window _window;
            Indie::GameComponents::Map _map;
            std::vector<std::shared_ptr<Indie::GameComponents::APlayer>> _players;
    };
};