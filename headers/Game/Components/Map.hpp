/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#pragma once

#include "Model.hpp"
#include "Box.hpp"
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
                bool isCollisionAt(Vector2 position, float radius) const;
            protected:
            private:
                Vector3 _mapPosition;
                Raylib::Image _imMap;
                Raylib::Texture2D _cubicmap;
                Raylib::Texture2D _texture;
                Raylib::Mesh _mesh;
                Raylib::ImageColors _mapPixels;
                Raylib::Model _model;
                std::vector<std::shared_ptr<Indie::GameComponents::Box>> _boxes;
        };
    };
};