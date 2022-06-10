/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#pragma once
#include "Raylib.hpp"
#include "Map.hpp"
#include <iostream>
#include <array>

namespace Indie {
    namespace GameComponents {
        class APlayer {
            public:
                APlayer(Raylib &raylib, Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath);
                ~APlayer() = default;
                void display() const;
                bool getIsAlive() const;
                virtual void move() = 0;
            protected:
                Raylib &_Raylib;
                Map &_Map;
                bool _isAlive = true;
                Vector3 _position;
                Texture2D _texture;
                std::array<KeyboardKey, 5> _keyMap;
        };
    };
};