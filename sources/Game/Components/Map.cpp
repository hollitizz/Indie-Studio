/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include "Const.hpp"
#include <iostream>
#include <cstdlib>

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
    for (auto &box : _boxes) {
        box->draw();
    }
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

void Indie::GameComponents::Map::genMapBlocks()
{
    std::cerr << "Map genMapBlocks" << std::endl;
    Vector3 boxPosition = {0, _mapPosition.y + 0.5f, 0};
    int randomNumber = 0;

    for (float z = -7; z < 6; ++z) {
        boxPosition.z = z;
        for (float x = -6; x < 7; ++x) {
            boxPosition.x = x;
            randomNumber = std::rand() % 100;
            if (!isCollisionAt({boxPosition.x, boxPosition.z}, 0.25) &&
                isValidPosition(boxPosition) && randomNumber <= 80) // 80% of chance to create a box
                _boxes.push_back(
                    std::make_shared<Indie::GameComponents::Box>(boxPosition)
                );
        }
    }
}

void Indie::GameComponents::Map::setDensity(size_t density)
{
    _density = density;
}

bool Indie::GameComponents::Map::isCollisionAt(Vector2 position, float radius) const
{
    auto cubicmap = getCubicmap();
    auto mapPixels = getMapPixels();

    for (int y = 0; y < cubicmap.height; y++) {
        for (int x = 0; x < cubicmap.width; x++)
        {
            if (mapPixels[y*cubicmap.width + x].r == 255 &&
                CheckCollisionCircleRec({position.x, position.y}, radius,
                Rectangle {
                    _mapPosition.x - 0.5f + x, _mapPosition.z - 0.5f + y, 1, 1
                    }
                ))
                return true;
        }
    }
    return false;
}

bool Indie::GameComponents::Map::isValidPosition(Vector3 position) const
{
    for (auto &pos : PLAYER_STARTS_POSITION) {
        if (pos.x == position.x && pos.y == position.z ||
            pos.x + 1 == position.x && pos.y == position.z ||
            pos.x - 1 == position.x && pos.y == position.z ||
            pos.x == position.x && pos.y + 1 == position.z ||
            pos.x == position.x && pos.y - 1 == position.z)
            return false;
    }
    return true;
}
