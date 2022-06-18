/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Model
*/

#include "Model.hpp"
#include <iostream>

Raylib::Model::Model(Raylib::Mesh &mesh, Raylib::Texture2D &texture)
{
    std::cerr << "Model Init from image" << std::endl;
    _model = LoadModelFromMesh(mesh.getMesh());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture.getTexture();
}

Raylib::Model::Model(std::string model, Raylib::Texture2D &texture, Color color)
{
    std::cerr << "Model Init from string" << std::endl;
    _model = LoadModel(model.c_str());
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, texture.getTexture());
    _color = color;
}

Raylib::Model::~Model()
{
    std::cerr << "Model Destroy" << std::endl;
}

::Model Raylib::Model::getModel() const
{
    return _model;
}

void Raylib::Model::draw(Vector3 position) const
{
    DrawModel(_model, position, 1, _color);
}

void Raylib::Model::drawExAt(Vector3 position, Vector3 rotationAxis, float rotationAngle) const
{
    DrawModelEx(_model, position, rotationAxis, rotationAngle, Vector3{ 0.3f, 0.3f, 0.3f }, _color);
}
