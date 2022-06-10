/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Mesh
*/

#pragma once

#include "Image.hpp"

namespace Raylib {
    class Mesh {
        public:
            Mesh(Raylib::Image image);
            ~Mesh();
            ::Mesh getMesh() const;
        protected:
        private:
            ::Mesh _mesh;
    };
}