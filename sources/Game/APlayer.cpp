/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#include "APlayer.hpp"

Indie::GameComponent::APlayer::APlayer(Raylib &raylib, Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath):
    _Raylib(raylib), _Map(map), _keyMap(keyMap)
{
    _texture = _Raylib.loadTexture(texturePath);
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
}

void Indie::GameComponent::APlayer::display() const
{
    _Raylib.drawCubeTexture(_texture, _position);
}

bool Indie::GameComponent::APlayer::getIsAlive() const
{
    return _isAlive;
}