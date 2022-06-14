/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#include "Human.hpp"

Indie::GameComponents::Human::Human(
    Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath
):
    APlayer(map, position, keyMap, texturePath)
{}

Indie::GameComponents::Human::~Human()
{}

void Indie::GameComponents::Human::move()
{
    Vector3 mapPosition = _Map.getMapPosition();
    Texture2D cubicmap = _Map.getCubicmap();
    std::vector<Color> mapPixels = _Map.getMapPixels();
    float playerRadius = 0.25;
    Vector3 oldPlayerPosition = _position;

    if (IsKeyPressed(_keyMap[0])) putBomb();
    if (IsKeyDown(_keyMap[1])) _position.z -= 0.1;// Z
    if (IsKeyDown(_keyMap[2])) _position.z += 0.1;// S
    if (IsKeyDown(_keyMap[3])) _position.x -= 0.1;// A
    if (IsKeyDown(_keyMap[4])) _position.x += 0.1;// D

    Vector2 playerPos = { _position.x, _position.z };
    int playerCellX = playerPos.x - mapPosition.x + 0.5;
    int playerCellY = playerPos.y - mapPosition.z + 0.5;
    if (playerCellX < 0)
        playerCellX = 0;
    else if (playerCellX >= cubicmap.width)
        playerCellX = cubicmap.width - 1;
    if (playerCellY < 0)
        playerCellY = 0;
    else if (playerCellY >= cubicmap.height)
        playerCellY = cubicmap.height - 1;
    if (_Map.isCollisionAt({playerPos.x, oldPlayerPosition.z}, playerRadius))
        _position.x = oldPlayerPosition.x;
    if (_Map.isCollisionAt({oldPlayerPosition.x, playerPos.y}, playerRadius))
        _position.z = oldPlayerPosition.z;
}