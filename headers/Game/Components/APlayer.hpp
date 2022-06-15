/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#pragma once
#include "Map.hpp"
#include "Texture2D.hpp"
#include "Bomb.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <memory>

namespace Indie {
    namespace GameComponents {
        class APlayer {
            public:
                APlayer(Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath);
                ~APlayer() = default;
                void display() const;
                bool getIsAlive() const;
                void setIsAlive(bool alive);
                void pauseBombs();
                void resumeBombs();
                void putBomb();
                Vector3 getPosition() const;
                size_t getBombsLen() const;
                std::shared_ptr<Indie::GameComponents::Bomb> getBomb(size_t index) const;
                std::shared_ptr<Indie::GameComponents::Bomb> popBomb();
                virtual void move() = 0;
            protected:
                Map &_Map;
                bool _isAlive = true;
                Vector3 _position;
                const Raylib::Texture2D &_texture;
                std::array<KeyboardKey, 5> _keyMap;
            private:
                size_t _maximumBomb = 1;
                std::vector<std::shared_ptr<Indie::GameComponents::Bomb>> _bombs;
        };
    };
};