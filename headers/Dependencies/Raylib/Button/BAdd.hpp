/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BAdd
*/

#pragma once
#include "Game.hpp"
#include "Button.hpp"

namespace Indie {
    namespace Scenes {
        class BAdd: public Button {
            public:
                BAdd(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BAdd(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);

                ~BAdd() = default;
                void run() override;
            private:
                Indie::Game &_game;
        };
    };
};