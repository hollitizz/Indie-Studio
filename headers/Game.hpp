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

namespace Indie {
    class Game {
        public:
            Game();
            ~Game();
            Raylib::Window getWindow() const;
            Indie::GameComponent::Map getMap() const;
            std::vector<std::shared_ptr<Indie::GameComponent::Human>> getPlayers() const;
        private:
            Vector2 _mapDeplacement = {9, 0};
            Vector3 _mapPosition = { -16 + _mapDeplacement.x, 0, -8 + _mapDeplacement.y };
            Raylib::Window _window;
            Indie::GameComponent::Map _map;
            std::vector<std::shared_ptr<Indie::GameComponent::APlayer>> _players;
    };
};