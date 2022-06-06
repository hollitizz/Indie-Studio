/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** AI
*/

#pragma once

#include "APlayer.hpp"

namespace Indie {
    namespace Game {
        class AI: public APlayer {
            public:
                AI(Raylib &raylib, bool isAi, Vector2 position, std::string texturePath);
                ~AI();
                void move() override;
            protected:
            private:
        };
    };
};
