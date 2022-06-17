/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Const.hpp"
#include <cmath>
#include <unistd.h>
#include <iostream>

Indie::GameComponents::Bomb::Bomb(Indie::GameComponents::Map &map, Vector3 position,
    Vector3 bombSize, size_t explosionRange, Raylib::Model &modelBomb, std::string modelBombAnimationPath):
    _map(map), _position({std::round(position.x), position.y, std::round(position.z)}),
    _bomb(_position, bombSize), _explosionRange(explosionRange), _clockExplosion(TIME_BEFORE_EXPLOSION),
    _clockVanish(TIME_BEFORE_VANISH), _size(bombSize), _model(modelBomb), _modelAnimation(modelBombAnimationPath)
{
}

Indie::GameComponents::Bomb::~Bomb()
{
}

std::vector<Vector3> Indie::GameComponents::Bomb::getExplosionsPos() const
{
    std::vector<Vector3> explosion;

    explosion.push_back(_position);
    for (size_t i = 1; i <= _explosionRange; ++i) {
        if (_map.isCollisionAt({_position.x + i, _position.z}))
            break;
        explosion.push_back({_position.x + i, _position.y, _position.z});
    }
    for (size_t i = 1; i <= _explosionRange; ++i) {
        if (_map.isCollisionAt({_position.x - i, _position.z}))
            break;
        explosion.push_back({_position.x - i, _position.y, _position.z});
    }
    for (size_t i = 1; i <= _explosionRange; ++i) {
        if (_map.isCollisionAt({_position.x, _position.z + i}))
            break;
        explosion.push_back({_position.x, _position.y, _position.z + i});
    }
    for (size_t i = 1; i <= _explosionRange; ++i) {
        if (_map.isCollisionAt({_position.x, _position.z - i}))
            break;
        explosion.push_back({_position.x, _position.y, _position.z - i});
    }
    return explosion;
}

void Indie::GameComponents::Bomb::displayExplosions(std::vector<Vector3> explosion) const
{
    for (auto &explosion : getExplosionsPos()) {
        _bomb.drawAt(explosion, {1, 1, 1}, WHITE);
    }
}

void Indie::GameComponents::Bomb::display()
{
    if (_clockVanish.isClockFinished()) {
        _shouldVanished = true;
        return;
    }
    if (_clockExplosion.isClockFinished()) {
        _isExploded = true;
        displayExplosions(getExplosionsPos());
        return;
    }
//    _bomb.draw(RED);
    _modelAnimation.setFrameCounter(_modelAnimation.getFrameCounter() + 1);
    UpdateModelAnimation(_model.getModel(), _modelAnimation.getAnimation()[0], _modelAnimation.getFrameCounter());
    if (_modelAnimation.getFrameCounter() >= _modelAnimation.getAnimation()[0].frameCount) _modelAnimation.setFrameCounter(0);
    DrawModelEx(_model.getModel(), {_position.x + 0.2f, -0.5f, _position.z + 0.2f}, {1, 0, 0}, -90.0f, {0.3f, 0.3f, 0.3f}, WHITE);
}

void Indie::GameComponents::Bomb::pause()
{
    _clockExplosion.pause();
    _clockVanish.pause();
}

void Indie::GameComponents::Bomb::resume()
{
    _clockExplosion.resume();
    _clockVanish.resume();
}

bool Indie::GameComponents::Bomb::getIsExploded() const
{
    return _isExploded;
}

bool Indie::GameComponents::Bomb::getShouldVanished() const
{
    return _shouldVanished;
}

size_t Indie::GameComponents::Bomb::getExplosionRange() const
{
    return _explosionRange;
}

Vector3 Indie::GameComponents::Bomb::getPosition() const
{
    return _position;
}

Vector3 Indie::GameComponents::Bomb::getSize() const
{
    return _size;
}
