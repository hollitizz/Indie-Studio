/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Player
*/

#include "Player.hpp"

Indie::GameComponents::Player::Player(
    Map &map, Vector2 position, bool isHuman, std::array<KeyboardKey, 5> keyMap, std::string texturePath,
    std::string modelPath, Color color, std::string modelBombPath,
    std::string modelBombAnimationPath, std::string modelExplosionPath
): _Map(map), _texture(texturePath), _model(modelPath, _texture, color), _color(color),
    _modelBomb(modelBombPath, _texture, WHITE), _modelBombAnimationPath(modelBombAnimationPath),
    _modelExplosion(modelExplosionPath, _texture, ORANGE), _keyMap(keyMap), _isHuman(isHuman)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
    _rotationAngle = -90;
    _rotationAxis = {1.0, 0.0, 0.0};
    _animations.push_back(std::make_shared<Raylib::ModelAnimation>(ANIMATIONS[RUN]));
    _animations.push_back(std::make_shared<Raylib::ModelAnimation>(ANIMATIONS[IDLE]));
    _modelAnimation = _animations[1];
}

void Indie::GameComponents::Player::setAnimation(std::string animation)
{
    if (animation == ANIMATIONS[RUN])
        _modelAnimation = _animations[0];
    else if (animation == ANIMATIONS[IDLE]) {
        _modelAnimation = _animations[1];
        _rotationAxis = {1.0, 0.0, 0.0};
    }
}

void Indie::GameComponents::Player::clearBonuses()
{
    _bonuses.clear();
    _speed = BASE_SPEED;
    _explosionRange = BASE_FIRE;
    _maximumBomb = BASE_BOMB;
    _wallPass = BASE_WALL_PASS;
}

void Indie::GameComponents::Player::putBomb()
{
    if (_bombs.size() < _maximumBomb) {
        _bombs.push_back(
            std::make_shared<Indie::GameComponents::Bomb>(_Map, _position, Vector3{1, 1, 1}, _explosionRange, _modelBomb, _modelBombAnimationPath, _modelExplosion)
        );
    }
}

void Indie::GameComponents::Player::setPosition(Vector2 position)
{
    _position = {position.x, _Map.getMapPosition().y + 0.5f, position.y};
}

void Indie::GameComponents::Player::computeBonus()
{
    switch (_bonuses.back()->getId()) {
        case BOMB_UP:
            _maximumBomb++;
            break;
        case FIRE_UP:
            _explosionRange++;
            break;
        case SPEED_UP:
            _speed += 0.02;
            break;
        case WALL_PASS:
            _wallPass = true;
            break;
        default:
            break;
    }
}

void Indie::GameComponents::Player::computeMove()
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

Vector3 Indie::GameComponents::Player::getPosition() const
{
    return _position;
}

size_t Indie::GameComponents::Player::getBombsLen() const
{
    return _bombs.size();
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::Player::getBomb(size_t index) const
{
    return _bombs[index];
}

void Indie::GameComponents::Player::pauseBombs()
{
    for (auto &bomb : _bombs) {
        bomb->pause();
    }
}

void Indie::GameComponents::Player::resumeBombs()
{
    for (auto &bomb : _bombs) {
        bomb->resume();
    }
}

std::shared_ptr<Indie::GameComponents::Bomb> Indie::GameComponents::Player::popBomb()
{
    auto bomb = *_bombs.begin();
    _bombs.erase(_bombs.begin());
    return bomb;
}

void Indie::GameComponents::Player::display()
{
    for (auto &Bomb : _bombs) {
        if (!Bomb->getShouldVanished())
            Bomb->display();
    }
    //DrawCube({_position.x + 0.25f, _position.y, _position.z + 0.25f}, 0.5, 1, 0.5, _color);
    _modelAnimation->setFrameCounter(_modelAnimation->getFrameCounter() + 1);
    UpdateModelAnimation(_model.getModel(), _modelAnimation->getAnimation()[0], _modelAnimation->getFrameCounter());
    if (_modelAnimation->getFrameCounter() >= _modelAnimation->getAnimation()[0].frameCount) _modelAnimation->setFrameCounter(0);
    if (_isAlive)
        _model.drawExAt({_position.x + 0.25f, _position.y - 0.5f, _position.z + 0.25f},
            _rotationAxis, _rotationAngle, {0.3f, 0.3f, 0.3f}
        );
}

bool Indie::GameComponents::Player::getIsAlive() const
{
    return _isAlive;
}

void Indie::GameComponents::Player::setIsAlive(bool alive)
{
    _isAlive = alive;
}

void Indie::GameComponents::Player::humanMove()
{
    if (IsKeyPressed(_keyMap[0])) putBomb();
    if (IsKeyDown(_keyMap[1])){
        _movement.y -= 1;
        _rotationSide = UP;
    }// Z
    if (IsKeyDown(_keyMap[2])){
        _movement.y += 1;
        _rotationSide = DOWN;
    }// S
    if (IsKeyDown(_keyMap[3])){
        _movement.x -= 1;
        _rotationSide = LEFT;
    }// A
    if (IsKeyDown(_keyMap[4])){
        _movement.x += 1;
        _rotationSide = RIGHT;
    }// D
}

void Indie::GameComponents::Player::aiMove()
{
    int aiMove = std::ceil(std::rand() % 10);

    _movement = {0, 0};
    if (aiMove == 0) putBomb();
    if (aiMove == 1 || aiMove == 2) {
        _movement.y -= 1;
        _rotationSide = UP;
    }// Z
    if (aiMove == 3 || aiMove == 4) {
        _movement.y += 1;
        _rotationSide = DOWN;
    }// S
    if (aiMove == 5 || aiMove == 6) {
        _movement.x -= 1;
        _rotationSide = LEFT;
    }// A
    if (aiMove == 7 || aiMove == 8) {
        _movement.x += 1;
        _rotationSide = RIGHT;
    }// D
}

void Indie::GameComponents::Player::move()
{
    _movement = {0, 0};
    if (_isHuman) {
        humanMove();
    } else {
        aiMove();
    }
    computeMove();
}