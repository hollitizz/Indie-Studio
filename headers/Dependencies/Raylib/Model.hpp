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
            Model(Raylib::Mesh &mesh, Raylib::Texture2D &texture);
            Model(std::string model, Raylib::Texture2D &texture);
            Model(const Image&) = delete;
            ~Model();
            ::Model getModel() const;
            void draw(Vector3 position)const;
        protected:
        private:
            ::Model _model;
    };
};