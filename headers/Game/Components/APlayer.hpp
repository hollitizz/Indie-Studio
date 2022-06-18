/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#pragma once
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
        class APlayer {
            public:
                APlayer(Map &map, Vector2 position, std::string texturePath,
                    std::string modelPath, Color color, std::string modelBombPath,
                    std::string modelBombAnimationPath, std::string modelExplosionPath);
                ~APlayer() = default;
                APlayer(const APlayer&) = delete;
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
                std::shared_ptr<Indie::GameComponents::Bomb> getBomb(size_t index) const;
                std::shared_ptr<Indie::GameComponents::Bomb> popBomb();
                virtual void move() = 0;
            protected:
                void computeBonus();
                Map &_Map;
                bool _isAlive = true;
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
            private:
                float _speed = 0.1;
                bool _wallPass = false;
                size_t _maximumBomb = 1;
                size_t _explosionRange = 1;
                std::vector<std::shared_ptr<Indie::GameComponents::Bomb>> _bombs;
        };
    };
};