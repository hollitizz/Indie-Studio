/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Button
*/

#pragma once
#include "State.hpp"
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
                Button(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                Button(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
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
                bool _btnAction;
            private:
                Rectangle _button;
                Raylib::Text _text;
                bool _isTextured;
                ButtonType _btnState;
                std::map<ButtonType, Texture2D> _textures;
                std::map<ButtonType, Color> _colors;
        };
    };
};