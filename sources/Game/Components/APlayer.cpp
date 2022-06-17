/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** APlayer
*/

#include "APlayer.hpp"

Indie::GameComponents::APlayer::APlayer(
    Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath, std::string modelPath, Color color, std::string modelBombPath, std::string modelBombAnimationPath
): _Map(map), _keyMap(keyMap), _texture(texturePath), _model(modelPath, _texture), _color(color), _modelBomb(modelBombPath, _texture), _modelBombAnimationPath(modelBombAnimationPath)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
    _rotationAngle = -90;
    _rotationAxis = {1.0, 0.0, 0.0};
    _animations.push_back(std::make_shared<Raylib::ModelAnimation>(ANIMATIONS[RUN]));
    _animations.push_back(std::make_shared<Raylib::ModelAnimation>(ANIMATIONS[IDLE]));
    _modelAnimation = _animations[1];
}

void Indie::GameComponents::APlayer::setAnimation(std::string animation)
{
    if (animation == ANIMATIONS[RUN])
        _modelAnimation = _animations[0];
    else if (animation == ANIMATIONS[IDLE]) {
        _modelAnimation = _animations[1];
        _rotationAxis = {1.0, 0.0, 0.0};
    }
}

void Indie::GameComponents::APlayer::putBomb()
{
    if (_bombs.size() < _maximumBomb) {
        _bombs.push_back(
            std::make_shared<Indie::GameComponents::Bomb>(_Map, _position, Vector3{1, 1, 1}, _explosionRange, _modelBomb, _modelBombAnimationPath)
        );
    }
}

void Indie::GameComponents::APlayer::setPosition(Vector2 position)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
}

void Indie::GameComponents::APlayer::computeBonus()
{
    switch (_bonuses.back()->getId()) {
        case BOMB_UP:
            _maximumBomb++;
            break;
        case FIRE_UP:
            _explosionRange++;
            break;
        case SPEED_UP:
            _speed += 0.1;
            break;
        case WALL_PASS:
            _wallPass = true;
            break;
        default:
            break;
    }
}

void Indie::GameComponents::APlayer::computeMove()
{
    int bonusIndex = -1;

    _movement.x *= _speed;
    _movement.y *= _speed;
    if ((!_Map.isCollisionWithBoxAt({_position.x + _movement.x, _position.z}) || _wallPass) &&
        !_Map.isCollisionAt({_position.x + _movement.x, _position.z})) _position.x += _movement.x;
    else _movement.x = 0;
    if ((!_Map.isCollisionWithBoxAt({_position.x, _position.z + _movement.y}) || _wallPass) &&
        !_Map.isCollisionAt({_position.x, _position.z + _movement.y})) _position.z += _movement.y;
    else _movement.y = 0;
    bonusIndex = _Map.getBonusIfExistAt({_position.x, _position.z});
    if (bonusIndex != -1) {
        _bonuses.push_back(_Map.pickBonus(bonusIndex));
        computeBonus();
    }
    _rotationAngle = ROTATION_ANGLE[_rotationSide];
    _rotationAxis = ROTATION[_rotationSide];
    (_movement.x != 0 || _movement.y != 0) ?
        _modelAnimation = _animations[0] : _modelAnimation = _animations[1];
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
    // DrawCube({_position.x + 0.25f, _position.y, _position.z + 0.25f}, 0.5, 1, 0.5, _color);
    _modelAnimation->setFrameCounter(_modelAnimation->getFrameCounter() + 1);
    UpdateModelAnimation(_model.getModel(), _modelAnimation->getAnimation()[0], _modelAnimation->getFrameCounter());
    if (_modelAnimation->getFrameCounter() >= _modelAnimation->getAnimation()[0].frameCount) _modelAnimation->setFrameCounter(0);
    if (_isAlive)
        DrawModelEx(
            _model.getModel(),
            {_position.x + 0.25f, _position.y - 0.5f, _position.z + 0.25f},
            _rotationAxis, _rotationAngle, Vector3{ 0.3f, 0.3f, 0.3f },
            _color
        );
}

bool Indie::GameComponents::APlayer::getIsAlive() const
{
    return _isAlive;
}

void Indie::GameComponents::APlayer::setIsAlive(bool alive)
{
    _isAlive = alive;
}