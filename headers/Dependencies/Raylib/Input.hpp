/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Input
*/

#pragma once
#include "State.hpp"
#include "Text.hpp"
#include <map>
#include <iostream>


namespace Indie {
    namespace Scenes {
        typedef struct InputColor_s {
            Color color;
            Color hoverColor;
            Color pressedColor;
        } InputColor;
        class Input {
            public:
                Input(Vector2 size, Vector2 position);

                ~Input() = default;

                void event();
                void display();

                void setPosition(Vector2 pos);

                enum InputType {
                    Normal,
                    Hover,
                    Click
                };
            protected:
            private:
                Rectangle _box;
                bool _mouseOnText;
                Raylib::Text _input;
                // Font _font;
                // int _fontSize;
                int _framesCounter;
        };
    };
};
