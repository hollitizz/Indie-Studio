/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Mesh
*/

#include "Mesh.hpp"
#include <iostream>

Raylib::Mesh::Mesh(const Raylib::Image &image)
{
    std::cerr << "Mesh Init" << std::endl;
    _mesh = GenMeshCubicmap(image.getImage(), Vector3{1, 1, 1});
}

Raylib::Mesh::~Mesh()
{
    std::cerr << "Mesh Destroy" << std::endl;
    UnloadMesh(_mesh);
}

::Mesh Raylib::Mesh::getMesh() const
{
    return _mesh;
}
