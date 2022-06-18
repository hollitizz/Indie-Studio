/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** AI
*/

#pragma once

#include "APlayer.hpp"

namespace Indie {
    namespace GameComponents {
        class AI: public APlayer {
            public:
                AI(Map &map, Vector2 position, std::string texturePath, std::string modelPath, Color color,
                    std::string modelAnimationPath, std::string modelBombPath, std::string modelBombAnimationPath,
                    std::string modelExplosionPath);
                virtual ~AI();
                void move() override;
            protected:
            private:
        };
    };
};