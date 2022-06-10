/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

Indie::GameComponents::Map::Map(Raylib &raylib, Vector3 mapPosition) : _Raylib(raylib), _mapPosition(mapPosition)
{
    std::cout << "Map init" << std::endl;
    Image imMap = _Raylib.loadImage("assets/Game/Maps/basic_bomberman_map.png");
    _cubicmap = _Raylib.loadTextureFromImage(imMap);
    _mesh = _Raylib.genMeshCubicmap(imMap, Vector3{1, 1, 1});
    _mapTexture = _Raylib.loadTexture("assets/Game/Maps/exemple_texture.png");
    _model = _Raylib.loadModelFromMesh(_mesh, _mapTexture);
    _mapPixels = _Raylib.loadImageColors(imMap);
    _Raylib.unloadImage(imMap);
}

Indie::GameComponents::Map::~Map()
{
    _Raylib.unloadTexture(_cubicmap);
    _Raylib.unloadTexture(_mapTexture);
    _Raylib.unloadModel(_model);
    std::cout << "Map destructor" << std::endl;
}

void Indie::GameComponents::Map:: display() const
{
    _Raylib.drawModel(_model, _mapPosition);
}

Texture2D Indie::GameComponents::Map::getCubicmap() const
{
    return _cubicmap;
}

Vector3 Indie::GameComponents::Map::getMapPosition() const
{
    return _mapPosition;
}

std::vector<Color> Indie::GameComponents::Map::getMapPixels() const
{
    return _mapPixels;
}
