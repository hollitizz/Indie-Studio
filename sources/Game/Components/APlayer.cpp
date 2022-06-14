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

void Indie::GameComponents::APlayer::putBomb()
{
    if (_bombs.size() < _maximumBomb) {
        _bombs.push_back(
            std::make_shared<Indie::GameComponents::Bomb>(_position, Vector3{1, 1, 1}, size_t{1})
        );
    }
}

size_t Indie::GameComponents::APlayer::getBombsLen() const
{
    return _bombs.size();
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::APlayer::getBomb(size_t index) const
{
    return _bombs[index];
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::APlayer::popBomb()
{
    auto bomb = *_bombs.begin();
    _bombs.erase(_bombs.begin());
    return bomb;
}

void Indie::GameComponents::APlayer::display() const
{
    for (auto &Bomb : _bombs) {
        Bomb->display();
    }
    DrawCubeTexture(_texture.getTexture(), _position, 0.5, 1, 0.5, WHITE);
}

bool Indie::GameComponents::APlayer::getIsAlive() const
{
    return _isAlive;
}