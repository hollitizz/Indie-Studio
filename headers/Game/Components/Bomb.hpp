/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Bomb
*/

#pragma once

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <stdlib.h>
#else
    #error "OS not supported!"
#endif

#include "Sound.hpp"
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
                Bomb(Indie::GameComponents::Map &map, Raylib::Sound &soundBomb,
                    Vector3 position, Vector3 bombSize, size_t _explosionRange, Raylib::Model &modelBomb, std::string modelBombAnimationPath, Raylib::Model &modelExplosion);
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
                bool _playSound = true;
                bool _isExploded = false;
                bool _shouldVanished = false;
                size_t _explosionRange;
                Raylib::Clock _clockExplosion;
                Raylib::Clock _clockVanish;
                Raylib::Model _model;
                Raylib::ModelAnimation _modelAnimation;
                Raylib::Model _modelExplosion;
                Raylib::Sound &_soundBomb;
        };
    };
};