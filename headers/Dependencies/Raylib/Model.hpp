/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Model
*/

#pragma once
#include "Texture2D.hpp"
#include "Image.hpp"
#include "Mesh.hpp"
#include "ImageColors.hpp"
#include <string>

namespace Raylib {
   class Model {
        public:
            Model(std::string image, std::string texturePath);
            ~Model();
            ::Model getModel() const;
            Raylib::Texture2D getCubicmap() const;
            Raylib::ImageColors getMapPixels() const;
            void draw(Vector3 position)const;
        protected:
        private:
            Raylib::Image _imMap;
            ::Model _model;
            Raylib::Texture2D _cubicmap;
            Raylib::Texture2D _texture;
            Raylib::Mesh _mesh;
            Raylib::ImageColors _mapPixels;
    };
};