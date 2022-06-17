/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Bonus
*/

#pragma once

#include "Cube.hpp"
#include <cstdlib>
#include <cmath>

namespace Indie {
    namespace GameComponents {
        enum BONUS_ID{
            BOMB_UP,
            FIRE_UP,
            SPEED_UP,
            WALL_PASS
        };
        class Bonus {
            public:
                Bonus(Vector3 pos, BONUS_ID id, Raylib::Texture2D &texture):
                _bonus({pos.x, pos.y - 0.5f, pos.z}, {1, 0.1, 1}), _texture(texture), _id(id) {};
                ~Bonus() = default;
                Vector3 getPosition() const { return _bonus.getPosition(); };
                BONUS_ID getId() const { return _id; };
                void draw() { _bonus.draw(_texture); }
            private:
                Raylib::Cube _bonus;
                Raylib::Texture2D &_texture;
                BONUS_ID _id;
        };
    };
};