/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Player
*/

#pragma once
#include "Sound.hpp"
#include "Map.hpp"
#include "Texture2D.hpp"
#include "ModelAnimation.hpp"
#include "Bomb.hpp"
#include "Const.hpp"
#include "Bonus.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <memory>

namespace Indie {
    namespace GameComponents {
        class Player {
            public:
                Player(Map &map, Raylib::Sound &_soundBomb, Vector2 position, bool isHuman, std::array<KeyboardKey, 5> keyMap,
                    std::string texturePath, std::string modelPath, Color color, std::string modelBombPath,
                    std::string modelBombAnimationPath, std::string modelExplosionPath);
                ~Player() = default;
                Player(const Player&) = delete;
                void display();
                bool getIsAlive() const;
                void setIsAlive(bool alive);
                void pauseBombs();
                void resumeBombs();
                void putBomb();
                void setAnimation(std::string animation);
                void computeMove();
                Vector3 getPosition() const;
                void setPosition(Vector2 position);
                size_t getBombsLen() const;
                void clearBonuses();
                void setIsHuman(bool isHuman);
                bool getIsHuman();
                std::shared_ptr<Indie::GameComponents::Bomb> getBomb(size_t index) const;
                std::shared_ptr<Indie::GameComponents::Bomb> popBomb();
                void move();
            protected:
            private:
                void aiMove();
                void humanMove();
                void computeBonus();
                Map &_Map;
                bool _isAlive = true;
                bool _isHuman;
                std::array<KeyboardKey, 5> _keyMap;
                Vector3 _position;
                Raylib::Texture2D _texture;
                Raylib::Model _model;
                Color _color;
                Vector2 _movement;
                Vector3 _rotationAxis;
                ROTATION_SIDE _rotationSide = DOWN;
                float _rotationAngle;
                std::shared_ptr<Raylib::ModelAnimation> _modelAnimation;
                std::vector<std::shared_ptr<Raylib::ModelAnimation>> _animations;
                std::vector<std::shared_ptr<Indie::GameComponents::Bonus>> _bonuses;
                Raylib::Model _modelBomb;
                std::string _modelBombAnimationPath;
                Raylib::Model _modelExplosion;
                float _speed = BASE_SPEED;
                bool _wallPass = BASE_WALL_PASS;
                size_t _maximumBomb = BASE_BOMB;
                size_t _explosionRange = BASE_FIRE;
                std::vector<std::shared_ptr<Indie::GameComponents::Bomb>> _bombs;
                Raylib::Sound &_soundBomb;
        };
    };
};