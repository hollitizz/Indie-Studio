/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BExit
*/

#pragma once
#include "Button.hpp"

namespace Indie {
    namespace Scenes {
        class BExit: public Button {
            public:
                BExit(State state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BExit(State state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);
                ~BExit() = default;
                void run() override;
        };
    };
};