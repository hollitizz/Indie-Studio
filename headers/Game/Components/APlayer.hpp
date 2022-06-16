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
#include <iostream>
#include <vector>
#include <array>
#include <memory>

namespace Indie {
    namespace GameComponents {
        class APlayer {
            public:
                APlayer(const Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath, std::string modelPath, Color color, std::string modelAnimationPath);
                ~APlayer() = default;
                void display();
                bool getIsAlive() const;
                void putBomb();
                size_t getBombsLen() const;
                std::shared_ptr<Indie::GameComponents::Bomb> getBomb(size_t index) const;
                std::shared_ptr<Indie::GameComponents::Bomb> popBomb();
                virtual void move() = 0;
            protected:
                const Map &_Map;
                bool _isAlive = true;
                Vector3 _position;
                Raylib::Texture2D _texture;
                std::array<KeyboardKey, 5> _keyMap;
                Raylib::Model _model;
                Color _color;
                Raylib::ModelAnimation _modelAnimation;
                Vector3 _rotationAxis;
                float _rotationAngle;
            private:
                size_t _maximumBomb = 2;
                std::vector<std::shared_ptr<Indie::GameComponents::Bomb>> _bombs;
        };
    };
};