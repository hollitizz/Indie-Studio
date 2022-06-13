/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#include "APlayer.hpp"

Indie::GameComponents::APlayer::APlayer(
    const Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath
):
    _Map(map), _keyMap(keyMap), _texture(texturePath)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
}

void Indie::GameComponents::APlayer::display() const
{
    DrawCubeTexture(_texture.getTexture(), _position, 0.5, 1, 0.5, WHITE);
}

bool Indie::GameComponents::APlayer::getIsAlive() const
{
    return _isAlive;
}