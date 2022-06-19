/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BIa
*/

#pragma once
#include "Button.hpp"

namespace Indie {
    namespace Scenes {
        class BIa: public Button {
            public:
                BIa(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BIa(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);
                ~BIa() = default;
                void run() override;
                bool getIsIa();
            private:
                bool _isIa = false;
        };
    };
};