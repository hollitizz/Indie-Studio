/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** BExit
*/

#include "BExit.hpp"
#include "raylib.h"

Indie::Scenes::BExit::BExit(State state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(state, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BExit::BExit(State state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    Button(state, size, position, text, fontSize, font, color)
{
}

void Indie::Scenes::BExit::run()
{
    _btnAction = true;
    CloseWindow();
    std::cerr << "Exit Game" << std::endl;
}