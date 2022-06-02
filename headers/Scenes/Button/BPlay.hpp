/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BPlay
*/

#pragma once
#include "Button.hpp"

namespace Indie {
    namespace Scenes {
        class BPlay: public Button {
            public:
                BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);

                ~BPlay() = default;
                void run() override;
        };
    };
};