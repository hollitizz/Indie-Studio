/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Slider
*/

#include <iostream>
#include "Slider.hpp"
#include "raylib.h"

Indie::Scenes::Slider::Slider(Vector2 size, Vector2 position, int min, int max):
    _box({position.x, position.y, size.x, size.y}),
    _input("< 0 >", BLACK, 30), _min(min), _max(max), _value(min)
{
    _framesCounter = 0;
}

Indie::Scenes::Slider::Slider(std::string name, Vector2 size, Vector2 position):
    _box({position.x, position.y, size.x, size.y}),
    _input(name, BLACK, 30)
{
    _framesCounter = 0;
}

void Indie::Scenes::Slider::event()
{
    _mouseOnText = CheckCollisionPointRec(GetMousePosition(), _box);
    if (_mouseOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        if (IsKeyPressed(KEY_RIGHT) && _value != _max) {
            _value += 10;
            _input.setText("< " + std::to_string(_value) + " >");
        } else if (IsKeyPressed(KEY_LEFT) && _value != _min) {
            _value -= 10;
            _input.setText("< " + std::to_string(_value) + " >");
        }

    } else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (_mouseOnText)
        _framesCounter++;
    else
        _framesCounter = 0;
}

void Indie::Scenes::Slider::display()
{
    DrawRectangleRec(_box, LIGHTGRAY);
    if (_mouseOnText)
        DrawRectangleLines((int)_box.x, (int)_box.y, (int)_box.width, (int)_box.height, RED);
    else
        DrawRectangleLines((int)_box.x, (int)_box.y, (int)_box.width, (int)_box.height, DARKGRAY);

    _input.setPosition({_box.x + _box.width / 2 - _input.getSize().x / 2, _box.y + _box.height / 2 - _input.getSize().y / 2});
    _input.draw();
}

void Indie::Scenes::Slider::setPosition(Vector2 pos)
{
    _box.x = pos.x;
    _box.y = pos.y;
}

int Indie::Scenes::Slider::getValue()
{
    return _value;
}