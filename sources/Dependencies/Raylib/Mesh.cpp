/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Mesh
*/

#include "Mesh.hpp"

Raylib::Mesh::Mesh(Raylib::Image image)
{
    _mesh = GenMeshCubicmap(image.getImage(), Vector3{1, 1, 1});
}

Raylib::Mesh::~Mesh()
{
    UnloadMesh(_mesh);
}

::Mesh Raylib::Mesh::getMesh() const
{
    return _mesh;
}
