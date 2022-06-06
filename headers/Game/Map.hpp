/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#pragma once

#include "Raylib.hpp"
#include <vector>

namespace Indie {
    namespace Game {
        class Map {
            public:
                Map(Raylib &raylib, Vector3 mapPosition);
                ~Map();
                void display() const;
                Texture2D getCubicmap() const;
                Vector3 getMapPosition() const;
                std::vector<Color> getMapPixels() const;
            protected:
            private:
                Raylib &_Raylib;
                Vector3 _mapPosition;
                Image _imMap;
                Texture2D _cubicmap;
                Mesh _mesh;
                Texture2D _mapTexture;
                Model _model;
                std::vector<Color> _mapPixels;
        };
    };
};