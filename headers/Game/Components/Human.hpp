/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#pragma once
#include "APlayer.hpp"

namespace Indie {
    namespace GameComponents {
        class Human: public APlayer {
            public:
                Human(Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath, std::string modelPath, Color color, std::string modelAnimationPath, std::string modelBombPath, std::string modelBombAnimationPath, std::string modelExplosionPath);
                virtual ~Human();
                void move() override;
            protected:
            private:
        };
    };
};