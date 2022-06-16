/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#include "APlayer.hpp"

Indie::GameComponents::APlayer::APlayer(
    Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath, std::string modelPath, Color color, std::string modelAnimationPath
):
    _Map(map), _keyMap(keyMap), _texture(texturePath), _model(modelPath, _texture), _color(color), _modelAnimation(modelPath, texturePath, modelAnimationPath)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
    _rotationAngle = -90;
    _rotationAxis = {1.0, 0.0, 0.0};
}

void Indie::GameComponents::APlayer::putBomb()
{
    if (_bombs.size() < _maximumBomb) {
        _bombs.push_back(
            std::make_shared<Indie::GameComponents::Bomb>(_Map, _position, Vector3{1, 1, 1}, size_t{1})
        );
    }
}

Vector3 Indie::GameComponents::APlayer::getPosition() const
{
    return _position;
}

size_t Indie::GameComponents::APlayer::getBombsLen() const
{
    return _bombs.size();
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::APlayer::getBomb(size_t index) const
{
    return _bombs[index];
}

void Indie::GameComponents::APlayer::pauseBombs()
{
    for (auto &bomb : _bombs) {
        bomb->pause();
    }
}

void Indie::GameComponents::APlayer::resumeBombs()
{
    for (auto &bomb : _bombs) {
        bomb->resume();
    }
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::APlayer::popBomb()
{
    auto bomb = *_bombs.begin();
    _bombs.erase(_bombs.begin());
    return bomb;
}

void Indie::GameComponents::APlayer::display()
{
    for (auto &Bomb : _bombs) {
        if (!Bomb->getShouldVanished())
            Bomb->display();
    }
    _modelAnimation.setFrameCounter(_modelAnimation.getFrameCounter() + 1);
    UpdateModelAnimation(_model.getModel(), _modelAnimation.getAnimation()[0], _modelAnimation.getFrameCounter());
    if (_modelAnimation.getFrameCounter() >= _modelAnimation.getAnimation()[0].frameCount) _modelAnimation.setFrameCounter(0);
    if (_isAlive)
        DrawModelEx(_model.getModel(), _position, _rotationAxis, _rotationAngle, (Vector3){ 0.3f, 0.3f, 0.3f }, _color);
}

bool Indie::GameComponents::APlayer::getIsAlive() const
{
    return _isAlive;
}

void Indie::GameComponents::APlayer::setIsAlive(bool alive)
{
    _isAlive = alive;
}