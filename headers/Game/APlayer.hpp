/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#pragma once
#include "raylib.h"

namespace Indie {
    namespace Game {
        class APlayer {
            public:
                APlayer(Raylib &raylib, bool isAi, Vector2 position, std::string texturePath);
                ~APlayer();
            protected:
            private:
                bool isAlive = true;
                Raylib &_Raylib;
                bool isAi;

                Vector3 position;
                Texture2D texture;
        };
    };
};