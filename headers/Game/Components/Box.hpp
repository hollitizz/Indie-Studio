/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Box
*/

#pragma once

#include "Cube.hpp"

namespace Indie {
    namespace GameComponents {
        class Box {
            public:
                Box(Vector3 position);
                Box(const Box&) = delete;
                ~Box() = default;
                void draw() const;
                Vector3 getPosition() const;
            private:
                Raylib::Cube _box;
        };
    };
};
