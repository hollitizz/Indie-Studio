/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

Indie::GameComponent::Map::Map(Vector3 mapPosition) : _mapPosition(mapPosition),
_model(Raylib::Model("assets/Game/Maps/basic_bomberman_map.png", "assets/Game/Maps/exemple_texture.png"))
{
    std::cout << "Map init" << std::endl;
}

Indie::GameComponent::Map::~Map()
{
    std::cout << "Map destructor" << std::endl;
}

void Indie::GameComponent::Map::display() const
{
    _model.draw(_mapPosition);
}

Texture2D Indie::GameComponent::Map::getCubicmap() const
{
    return _model.getCubicmap().getTexture();
}

Vector3 Indie::GameComponent::Map::getMapPosition() const
{
    return _mapPosition;
}

std::vector<Color> Indie::GameComponent::Map::getMapPixels() const
{
    return _model.getMapPixels().getColors();
}
