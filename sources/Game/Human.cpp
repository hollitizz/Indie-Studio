/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Human
*/

#include "Human.hpp"

Indie::Game::Human::Human(Raylib &raylib, Map &map, Vector2 position, std::array<KeyboardKey, 5> keyMap, std::string texturePath):
    APlayer(raylib, map, position, keyMap, texturePath)
{}

Indie::Game::Human::~Human()
{
    _Raylib.unloadTexture(_texture);
}

void Indie::Game::Human::move()
{
    Vector2 playerPos = { _position.x, _position.z };
    Vector3 mapPosition = _Map.getMapPosition();
    Texture2D cubicmap = _Map.getCubicmap();
    std::vector<Color> mapPixels = _Map.getMapPixels();
    float playerRadius = 0.25;
    int playerCellX = playerPos.x - mapPosition.x + 0.5;
    int playerCellY = playerPos.y - mapPosition.z + 0.5;

    // if (IsKeyDown(_keyMap[0])) putBomb();
    if (IsKeyDown(_keyMap[1])) playerPos.y -= 0.1;// W
    if (IsKeyDown(_keyMap[2])) playerPos.y += 0.1;// S
    if (IsKeyDown(_keyMap[3])) playerPos.x -= 0.1;// A
    if (IsKeyDown(_keyMap[4])) playerPos.x += 0.1;// D
    if (playerCellX < 0)
        playerCellX = 0;
    else if (playerCellX >= cubicmap.width)
        playerCellX = cubicmap.width - 1;
    if (playerCellY < 0)
        playerCellY = 0;
    else if (playerCellY >= cubicmap.height)
        playerCellY = cubicmap.height - 1;
    for (int y = 0; y < cubicmap.height; y++)
    {
        for (int x = 0; x < cubicmap.width; x++)
        {
            if ((mapPixels[y*cubicmap.width + x].r == 255) &&
                (CheckCollisionCircleRec(playerPos, playerRadius,
                Rectangle {
                    mapPosition.x - 0.5f + x, mapPosition.z - 0.5f + y, 1, 1})))
                _position = {playerPos.x, _position.y, playerPos.y};
        }
    }
}