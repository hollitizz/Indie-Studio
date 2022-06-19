/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Choice
*/

#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "Text.hpp"
#include <map>
#include <iostream>
#include <vector>

namespace Indie {
    namespace Scenes {
        typedef struct ChoiceColor_s {
            Color color;
            Color hoverColor;
            Color pressedColor;
        } ChoiceColor;
        class Choice {
            public:
                Choice(std::vector<std::string> choices, Indie::Game &game, State &state, Vector2 size, Vector2 position, int fontSize, Font font,
                    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture);
                Choice(std::vector<std::string> choices, Indie::Game &game, State &state, Vector2 size, Vector2 position, int fontSize, Font font,
                    ChoiceColor color);

                ~Choice() = default;

                void event();
                void display();

                int getChoice() const;
                bool getBtnAction() const;
                void setPosition(Vector2 pos);
                void setChoices(std::vector<std::string> choices);

                enum ChoiceType {
                    Normal,
                    Hover,
                    Click
                };
            protected:
                void run();
                State &_State;
                Indie::Game &_Game;
                bool _btnAction;
            private:
                Rectangle _button;
                std::vector<std::string> _choices;
                Raylib::Text _text;
                int _choice;
                bool _isTextured;
                ChoiceType _btnState;
                std::map<ChoiceType, Texture2D> _textures;
                std::map<ChoiceType, Color> _colors;
        };
    };
};