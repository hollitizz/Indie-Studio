/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Map
*/

#include "Map.hpp"
#include "Const.hpp"
#include "Rectangle.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Indie::GameComponents::Map::Map(Vector3 mapPosition) : _mapPosition(mapPosition),
    _boxTexture("assets/Game/Maps/box_texture.png"),
    _imMap("assets/Game/Maps/basic_bomberman_map.png"), _cubicmap(_imMap),
    _mesh(_imMap), _texture("assets/Game/Maps/exemple_texture.png"),
    _mapPixels(_imMap),
    _model(_mesh, _texture)
{
    std::cerr << "Map init" << std::endl;
    _bonusTextures[Indie::GameComponents::BOMB_UP] = std::make_shared<Raylib::Texture2D>("assets/Game/Maps/BombUp.png");
    _bonusTextures[Indie::GameComponents::FIRE_UP] = std::make_shared<Raylib::Texture2D>("assets/Game/Maps/FireUp.png");
    _bonusTextures[Indie::GameComponents::SPEED_UP] = std::make_shared<Raylib::Texture2D>("assets/Game/Maps/SpeedUp.png");
    _bonusTextures[Indie::GameComponents::WALL_PASS] = std::make_shared<Raylib::Texture2D>("assets/Game/Maps/WallPass.png");
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
    for (auto &bonus : _bonuses) {
        bonus->draw();
    }
}

std::shared_ptr<Indie::GameComponents::Bonus> Indie::GameComponents::Map::pickBonus(int index)
{
    auto bonus = std::make_shared<Indie::GameComponents::Bonus>(*_bonuses[index]);
    _bonuses.erase(_bonuses.begin() + index);
    return bonus;
}

void Indie::GameComponents::Map::tryCreateBonus(Vector3 position)
{
    int isBonusSpawn = std::ceil(std::rand() % 5);
    Indie::GameComponents::BONUS_ID bonusType = static_cast<BONUS_ID>(std::ceil(std::rand() % 4));

    if (isBonusSpawn == 1) {
        _bonuses.push_back(std::make_shared<Indie::GameComponents::Bonus>(
                position,
                bonusType,
                *_bonusTextures[bonusType]
            )
        );
    }
}

int Indie::GameComponents::Map::getBonusIfExistAt(Vector2 position)
{
    Vector3 bonusPosition;
    Raylib::Rectangle hitBox({position.x, position.y}, {0.5, 0.5});

    for (int i = 0; i < _bonuses.size(); ++i) {
        bonusPosition = _bonuses[i]->getPosition();
        if (hitBox.isCollisionWithRec(
                {bonusPosition.x - 0.5f, bonusPosition.z - 0.5f},
                {1, 1}
            ))
            return i;
    }
    return -1;
}

void Indie::GameComponents::Map::cleanExplodedBoxes(std::vector<Vector3> explodedPoints)
{
    Vector3 position;

    for (int i = 0; i < _boxes.size(); ++i) {
        position = _boxes[i]->getPosition();
        for (auto &explodedPoint : explodedPoints) {
            if (position.x == explodedPoint.x && position.z == explodedPoint.z) {
                _boxes.erase(_boxes.begin() + i);
                tryCreateBonus(position);
            }
        }
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

    if (_density == 0)
        return;
    for (float z = -7; z < 6; ++z) {
        boxPosition.z = z;
        for (float x = -6; x < 7; ++x) {
            boxPosition.x = x;
            randomNumber = std::rand() % 100;
            if (!isCollisionAt({boxPosition.x, boxPosition.z}) &&
                isValidPosition(boxPosition) && randomNumber <= _density) // 80% of chance to create a box
                _boxes.push_back(
                        std::make_shared<Indie::GameComponents::Box>(
                            boxPosition, _boxTexture
                    )
                );
        }
    }
}

void Indie::GameComponents::Map::remMapBlocks()
{
    std::cerr << "Map remMapBlocks" << std::endl;
    _boxes.clear();
}

void Indie::GameComponents::Map::setDensity(size_t density)
{
    _density = density;
}

bool Indie::GameComponents::Map::isCollisionWithBoxAt(Vector2 position) const
{
    auto cubicmap = getCubicmap();
    auto mapPixels = getMapPixels();
    Vector3 boxPosition;
    Raylib::Rectangle hitBox({position.x, position.y}, {0.5, 0.5});

    for (auto &box : _boxes) {
        boxPosition = box->getPosition();
        if (hitBox.isCollisionWithRec(
                {boxPosition.x - 0.5f, boxPosition.z - 0.5f},
                {1, 1}
            ))
            return true;
    }
    return false;
}

bool Indie::GameComponents::Map::isCollisionAt(Vector2 position) const
{
    auto cubicmap = getCubicmap();
    auto mapPixels = getMapPixels();
    Raylib::Rectangle hitBox({position.x, position.y}, {0.5, 0.5});

    for (int y = 0; y < cubicmap.height; y++) {
        for (int x = 0; x < cubicmap.width; x++)
        {
            if (mapPixels[y*cubicmap.width + x].r == 255 &&
                hitBox.isCollisionWithRec(
                    {_mapPosition.x - 0.5f + x, _mapPosition.z - 0.5f + y},
                    {1, 1}
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
