/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Game
*/

#pragma once
#include "Music.hpp"
#include "Sound.hpp"
#include "Window.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Text.hpp"
#include <vector>
#include <memory>

namespace Indie {
    class Game {
        public:
            Game();
            Game(const Game&) = delete;
            ~Game();
            void preLoadGame();
            void loadGame();
            void killEntities(std::vector<Vector3> explodedPoints);
            Raylib::Window &getWindow();
            Vector2 getWindowSize() const;
            Indie::GameComponents::Map &getMap();
            std::vector<std::shared_ptr<Indie::GameComponents::Player>> getPlayers() const;
            std::vector<std::shared_ptr<Raylib::Text>> getNames() const;
            void rmPlayer();
            void addPlayer();
            void setNbAlivePlayers(int nb);
            const size_t getLastPlayer() const;
            const int getNbAlivePlayers() const;
            const int getNbPlayers() const;
            Raylib::Sound &getSoundBomb();
            Raylib::Music &getMusicMenu();
            Raylib::Cube _explosion;
        private:
            Vector2 _mapDeplacement = {9, 0};
            Vector3 _mapPosition = { -16 + _mapDeplacement.x, 0, -8 + _mapDeplacement.y };
            Raylib::Window _window;
            Indie::GameComponents::Map _map;
            std::vector<std::shared_ptr<Indie::GameComponents::Player>> _players;
            std::vector<std::shared_ptr<Raylib::Text>> _names;
            int _nbPlayers = 4;
            int _nbAlivePlayers;
            Raylib::Sound _soundBomb;
            Raylib::Music _musicMenu;
    };
};
