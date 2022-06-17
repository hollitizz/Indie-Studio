/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#pragma once

#include "Model.hpp"
#include "Box.hpp"
#include "Bonus.hpp"
#include <vector>
#include <memory>

namespace Indie {
    namespace GameComponents {
        class Map {
            public:
                Map(Vector3 mapPosition);
                ~Map();
                void display() const;
                Texture2D getCubicmap() const;
                Vector3 getMapPosition() const;
                std::vector<Color> getMapPixels() const;
                void genMapBlocks();
                void setDensity(size_t density);
                std::shared_ptr<Indie::GameComponents::Bonus> pickBonus(int index);
                int getBonusIfExistAt(Vector2 position);
                void tryCreateBonus(Vector3 position);
                void cleanExplodedBoxes(std::vector<Vector3> explodedPoints);
                bool isCollisionAt(Vector2 position) const;
                bool isCollisionWithBoxAt(Vector2 position) const;
            protected:
            private:
                bool isValidPosition(Vector3 position) const;
                Vector3 _mapPosition;
                Raylib::Texture2D _boxTexture;
                Raylib::Image _imMap;
                Raylib::Texture2D _cubicmap;
                Raylib::Texture2D _texture;
                Raylib::Mesh _mesh;
                Raylib::ImageColors _mapPixels;
                Raylib::Model _model;
                size_t _density = 80;
                std::vector<std::shared_ptr<Indie::GameComponents::Box>> _boxes;
                std::vector<std::shared_ptr<Indie::GameComponents::Bonus>> _bonuses;
        };
    };
};