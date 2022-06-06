/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#pragma once
#include "APlayer.hpp"

namespace Indie {
    namespace Game {
        class Human: public APlayer {
            public:
                Human(Raylib &raylib, Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath);
                virtual ~Human();
                void move() override;
            protected:
            private:
        };
    };
};