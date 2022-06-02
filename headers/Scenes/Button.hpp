/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Button
*/

#pragma once
#include "Raylib.hpp"
#include "State.hpp"
#include <map>

namespace Indie {
    namespace Scenes {
        class Button {
            public:
                Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Color color, Color hoverColor, Color pressedColor);
                Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font);

                ~Button() = default;

                virtual void event();
                virtual void display();

                bool getBtnAction() const;

                enum ButtonType {
                    Normal,
                    Hover,
                    Click
                };
            protected:
                virtual void run() = 0;
                Raylib &_Raylib;
            private:
                Rectangle _button;
                std::string _text;
                Font _font;
                int _fontSize;
                bool _isTextured;
                ButtonType _btnState;
                std::map<ButtonType, Texture2D> _textures;
                std::map<ButtonType, Color> _colors;
        };

        class BExit: public Button {
            public:
                BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Color color, Color hoverColor, Color pressedColor);
                BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font);
                ~BExit() = default;
                void run() override;
        };

        class BPlay: public Button {
            public:
                BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
                    Color color, Color hoverColor, Color pressedColor);
                BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font);
                ~BPlay() = default;
                void run() override;
        };
    };
};
