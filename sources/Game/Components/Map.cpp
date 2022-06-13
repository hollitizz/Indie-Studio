/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

Indie::GameComponents::Map::Map(Vector3 mapPosition) : _mapPosition(mapPosition),
    _model("assets/Game/Maps/basic_bomberman_map.png", "assets/Game/Maps/exemple_texture.png")
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
    return _model.getCubicmap().getTexture();
}

Vector3 Indie::GameComponents::Map::getMapPosition() const
{
    return _mapPosition;
}

std::vector<Color> Indie::GameComponents::Map::getMapPixels() const
{
    return _model.getMapPixels().getColors();
}
