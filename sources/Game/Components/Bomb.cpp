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

Indie::GameComponents::Bomb::Bomb(Vector3 position, Vector3 bombSize, size_t explosionRange):
    _position({std::round(position.x), position.y, std::round(position.z)}),
    _bomb(_position, bombSize), _explosionRange(explosionRange), _clockExplosion(TIME_BEFORE_EXPLOSION),
    _clockVanish(TIME_BEFORE_VANISH), _size(bombSize)
{
}

Indie::GameComponents::Bomb::~Bomb()
{
}

void Indie::GameComponents::Bomb::display()
{
    if (_clockVanish.isClockFinished()) {
        _shouldVanished = true;
        return;
    }
    if (_clockExplosion.isClockFinished()) {
        _isExploded = true;
        _bomb.draw(WHITE);
        return;
    }
    _bomb.draw(RED);
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
