/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Model
*/

#include "Model.hpp"
#include <iostream>

Raylib::Model::Model(std::string image, std::string texture):
    _imMap(image), _cubicmap(_imMap),
    _mesh(_imMap), _texture(texture),
    _mapPixels(_imMap)
{
    std::cerr << "Model Init" << std::endl;
    _model = LoadModelFromMesh(_mesh.getMesh());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture.getTexture();
}


Raylib::Model::~Model()
{
    std::cerr << "Model Destroy" << std::endl;
}

::Model Raylib::Model::getModel() const
{
    return _model;
}

const Raylib::Texture2D &Raylib::Model::getCubicmap() const
{
    return _cubicmap;
}

const Raylib::ImageColors &Raylib::Model::getMapPixels() const
{
    return _mapPixels;
}

void Raylib::Model::draw(Vector3 position) const
{
    DrawModel(_model, position, 1, WHITE);
}
