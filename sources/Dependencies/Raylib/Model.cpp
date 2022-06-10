/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Model
*/

#include "Model.hpp"


Raylib::Model::Model(std::string image, std::string texture):
    _imMap(Raylib::Image(image)), _cubicmap(Raylib::Texture2D(_imMap)),
    _mesh(Raylib::Mesh(_imMap)), _texture(Raylib::Texture2D(texture)),
    _mapPixels(Raylib::ImageColors(_imMap))
{
    _model = LoadModelFromMesh(_mesh.getMesh());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture.getTexture();
}


Raylib::Model::~Model()
{
}

::Model Raylib::Model::getModel() const
{
    return _model;
}

Raylib::Texture2D Raylib::Model::getCubicmap() const
{
    return _cubicmap;
}

Raylib::ImageColors Raylib::Model::getMapPixels() const
{
    return _mapPixels;
}

void Raylib::Model::draw(Vector3 position) const
{
    DrawModel(_model, position, 1, WHITE);
}
