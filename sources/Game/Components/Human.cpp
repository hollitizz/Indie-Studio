/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#include "Human.hpp"
#include <tuple>

Indie::GameComponents::Human::Human(
    Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath, std::string modelPath, Color color, std::string modelAnimationPath, std::string modelBombPath, std::string modelBombAnimationPath
):
    APlayer(map, position, keyMap, texturePath, modelPath, color, modelBombPath, modelBombAnimationPath)
{}

Indie::GameComponents::Human::~Human()
{}

void Indie::GameComponents::Human::move()
{
    Vector3 mapPosition = _Map.getMapPosition();
    Texture2D cubicmap = _Map.getCubicmap();
    std::vector<Color> mapPixels = _Map.getMapPixels();

    _movement = {0, 0};
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
    computeMove();
}