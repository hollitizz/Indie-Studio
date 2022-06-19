/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BPlay
*/

#pragma once
#include "Button.hpp"
#include "Input.hpp"
#include "Slider.hpp"
#include "Choice.hpp"

namespace Indie {
    namespace Scenes {
        class BPlay: public Button {
            public:
                BPlay(std::vector<std::shared_ptr<Input>> &_input, Slider &slider, Choice &_choice, Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BPlay(std::vector<std::shared_ptr<Input>> &_input, Slider &slider, Choice &_choice, Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);

                ~BPlay() = default;
                void run() override;
            private:
                std::vector<std::shared_ptr<Input>> &_input;
                Choice &_choice;
                Slider &_slider;
        };
    };
};