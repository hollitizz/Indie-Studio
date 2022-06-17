/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Slider
*/

#pragma once
#include "State.hpp"
#include "Text.hpp"
#include <map>
#include <iostream>


namespace Indie {
    namespace Scenes {
        class Slider {
            public:
                Slider(Vector2 size, Vector2 position, int min, int max);
                Slider(std::string name, Vector2 size, Vector2 position);

                ~Slider() = default;

                void event();
                void display();

                void setPosition(Vector2 pos);
                int getValue();
            protected:
            private:
                Rectangle _box;
                bool _mouseOnText;
                Raylib::Text _input;
                int _framesCounter;
                int _value;
                int _min;
                int _max;
        };
    };
};
