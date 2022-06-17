/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Input
*/

#include <iostream>
#include "Input.hpp"
#include "raylib.h"

Indie::Scenes::Input::Input(Vector2 size, Vector2 position):
    _box({position.x, position.y, size.x, size.y}),
    _input("", BLACK, 30)
{
    _framesCounter = 0;
}

Indie::Scenes::Input::Input(std::string name, Vector2 size, Vector2 position):
    _box({position.x, position.y, size.x, size.y}),
    _input(name, BLACK, 30)
{
    _framesCounter = 0;
}

void Indie::Scenes::Input::event()
{
    _mouseOnText = CheckCollisionPointRec(GetMousePosition(), _box);
    if (_mouseOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        for (int key = GetCharPressed(); key > 0; key = GetCharPressed())
            if (std::isalpha(key) && _input.getTextSize() < 12)
                _input.setText(_input.getText() + (char)key);

        if (IsKeyPressed(KEY_BACKSPACE))
            if (_input.getTextSize() > 0)
                _input.setText(_input.getText().substr(0, _input.getTextSize() - 1));

    } else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    
    if (_mouseOnText)
        _framesCounter++;
    else
        _framesCounter = 0;
}

void Indie::Scenes::Input::display()
{
    DrawRectangleRec(_box, LIGHTGRAY);
    if (_mouseOnText)
        DrawRectangleLines((int)_box.x, (int)_box.y, (int)_box.width, (int)_box.height, RED);
    else
        DrawRectangleLines((int)_box.x, (int)_box.y, (int)_box.width, (int)_box.height, DARKGRAY);

    DrawText(_input.getText().c_str(), (int)_box.x + 5, (int)_box.y + 8, 40, MAROON);

    if (_mouseOnText)
        if (_input.getTextSize() < 12)
            if (((_framesCounter/20)%2) == 0)
                DrawText("_", (int)_box.x + 8 + MeasureText(_input.getText().c_str(), 40), (int)_box.y + 12, 40, MAROON);
}

void Indie::Scenes::Input::setPosition(Vector2 pos)
{
    _box.x = pos.x;
    _box.y = pos.y;
}

std::string Indie::Scenes::Input::getText()
{
    return _input.getText();
}