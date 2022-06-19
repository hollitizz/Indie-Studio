/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Button
*/

#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "Text.hpp"
#include <map>
#include <iostream>

namespace Indie {
    namespace Scenes {
        typedef struct ButtonColor_s {
            Color color;
            Color hoverColor;
            Color pressedColor;
        } ButtonColor;
        class Button {
            public:
                Button(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                Button(Indie::Game &game, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    ButtonColor color);

                ~Button() = default;

                virtual void event();
                virtual void display();

                virtual bool getBtnAction() const;
                virtual void setPosition(Vector2 pos);

                enum ButtonType {
                    Normal,
                    Hover,
                    Click
                };
            protected:
                virtual void run() = 0;
                State &_State;
                Indie::Game &_Game;
                bool _btnAction;
                Raylib::Text _text;
            private:
                Rectangle _button;
                bool _isTextured;
                ButtonType _btnState;
                std::map<ButtonType, Texture2D> _textures;
                std::map<ButtonType, Color> _colors;
        };
    };
};