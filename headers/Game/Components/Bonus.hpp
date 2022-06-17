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
            BOMB,
            EXPLOSION_RANGE,
            SPEED,
            WALL_PASS
        };
        class Bonus {
            public:
                Bonus(Vector3 pos, Color color): _bonus({pos.x, pos.y - 0.5f, pos.z}, {1, 0.1, 1}), _color(color)
                { _id = static_cast<BONUS_ID>(std::ceil(std::rand() % 2)); };
                ~Bonus() = default;
                Vector3 getPosition() const { return _bonus.getPosition(); };
                BONUS_ID getId() const { return _id; };
                void draw() { _bonus.draw(_color); }
            private:
                Color _color;
                Raylib::Cube _bonus;
                BONUS_ID _id;
        };
    };
};