/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BSound
*/

#pragma once
#include "Button.hpp"

namespace Indie {
    namespace Scenes {
        class BSound: public Button {
            public:
                BSound(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BSound(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);
                ~BSound() = default;
                void run() override;
        };
    };
};