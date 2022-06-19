/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Blur
*/

#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "Text.hpp"
#include "Game.hpp"
#include <map>
#include <iostream>

namespace Indie {
    namespace Scenes {
        class Blur {
            public:
                Blur(Indie::Game &game, Vector2 size, Vector2 position, Color color);
                ~Blur() = default;
                virtual void display();
            protected:
            private:
                Rectangle _blur;
                Color _color;
                Indie::Game &_game;
        };
    };
};