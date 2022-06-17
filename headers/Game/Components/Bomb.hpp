/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Bomb
*/

#pragma once

#include "Cube.hpp"
#include "Clock.hpp"
#include "ModelAnimation.hpp"
#include "Map.hpp"
#include <vector>
#include <cstddef>
#include <ctime>

namespace Indie {
    namespace GameComponents {
        class Bomb {
            public:
                Bomb(Indie::GameComponents::Map &map,
                    Vector3 position, Vector3 bombSize, size_t _explosionRange, Raylib::Model &modelBomb, std::string modelBombAnimationPath);
                Bomb(const Bomb&) = delete;
                ~Bomb();
                void display();
                void pause();
                void resume();
                bool getIsExploded() const;
                bool getShouldVanished() const;
                void displayExplosions(std::vector<Vector3> explosion) const;
                std::vector<Vector3> getExplosionsPos() const;
                size_t getExplosionRange() const;
                Vector3 getPosition() const;
                Vector3 getSize() const;
            protected:
            private:
                Indie::GameComponents::Map &_map;
                Vector3 _position;
                Vector3 _size;
                Raylib::Cube _bomb;
                bool _isExploded = false;
                bool _shouldVanished = false;
                size_t _explosionRange;
                Raylib::Clock _clockExplosion;
                Raylib::Clock _clockVanish;
                Raylib::Model _model;
                Raylib::ModelAnimation _modelAnimation;
        };
    };
};