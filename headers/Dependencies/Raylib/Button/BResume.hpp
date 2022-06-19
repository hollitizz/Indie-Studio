/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BResume
*/

#pragma once
#include "Button.hpp"
#include "Input.hpp"
#include "Slider.hpp"
#include "Choice.hpp"

namespace Indie {
    namespace Scenes {
        class BResume: public Button {
            public:
                BResume(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BResume(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);

                ~BResume() = default;
                void run() override;
            private:
        };
    };
};