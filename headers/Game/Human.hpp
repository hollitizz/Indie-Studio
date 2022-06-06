/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#pragma once
#include "raylib.h"
#include "APlayer.hpp"

namespace Indie {
    namespace Game {
        class Human: public APlayer {
            public:
                Human(Raylib &raylib, bool isAi, Vector2 position, std::string texturePath);
                ~Human();
            protected:
            private:
                Raylib &_Raylib;
        };
    };
};