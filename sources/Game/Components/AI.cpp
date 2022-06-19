/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** AI
*/

#include "AI.hpp"

Indie::GameComponents::AI::AI(
    Map &map, Raylib::Sound &soundBomb, Vector2 position, std::string texturePath, std::string modelPath, Color color,
    std::string modelAnimationPath, std::string modelBombPath, std::string modelBombAnimationPath, std::string modelExplosionPath
):
    APlayer(map, soundBomb, position, texturePath, modelPath, color, modelBombPath, modelBombAnimationPath, modelExplosionPath)
{}

Indie::GameComponents::AI::~AI()
{}

void Indie::GameComponents::AI::move()
{
    Vector3 mapPosition = _Map.getMapPosition();
    Texture2D cubicmap = _Map.getCubicmap();
    std::vector<Color> mapPixels = _Map.getMapPixels();
    int aiMove = std::ceil(std::rand() % 5);

    _movement = {0, 0};
    // if (aiMove == 0) putBomb();
    if (aiMove == 1) {
        _movement.y -= 1;
        _rotationSide = UP;
    }// Z
    if (aiMove == 2) {
        _movement.y += 1;
        _rotationSide = DOWN;
    }// S
    if (aiMove == 3) {
        _movement.x -= 1;
        _rotationSide = LEFT;
    }// A
    if (aiMove == 4) {
        _movement.x += 1;
        _rotationSide = RIGHT;
    }// D
    computeMove();
}