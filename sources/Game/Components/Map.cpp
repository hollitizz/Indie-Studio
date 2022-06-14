/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

Indie::GameComponents::Map::Map(Vector3 mapPosition) : _mapPosition(mapPosition),
    _imMap("assets/Game/Maps/basic_bomberman_map.png"), _cubicmap(_imMap),
    _mesh(_imMap), _texture("assets/Game/Maps/exemple_texture.png"),
    _mapPixels(_imMap),
    _model(_mesh, _texture)
{
    std::cerr << "Map init" << std::endl;
}

Indie::GameComponents::Map::~Map()
{
    std::cerr << "Map destructor" << std::endl;
}

void Indie::GameComponents::Map::display() const
{
    _model.draw(_mapPosition);
}

Texture2D Indie::GameComponents::Map::getCubicmap() const
{
    return _cubicmap.getTexture();
}

Vector3 Indie::GameComponents::Map::getMapPosition() const
{
    return _mapPosition;
}

std::vector<Color> Indie::GameComponents::Map::getMapPixels() const
{
    return _mapPixels.getColors();
}
