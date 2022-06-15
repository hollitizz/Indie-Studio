/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Button
*/

#include <iostream>
#include "Button.hpp"
#include "raylib.h"

Indie::Scenes::Button::Button(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    _State(state), _text(text, BLACK), _isTextured(true), _fontSize(fontSize), _font(font),
    _button({position.x, position.y, size.x, size.y})
{
    _textures[Normal] = texture;
    _textures[Hover] = hoverTexture;
    _textures[Click] = pressedTexture;
}

Indie::Scenes::Button::Button(State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    ButtonColor color = {BLUE, ORANGE, RED}):
    _State(state), _text(text, BLACK), _isTextured(false), _fontSize(fontSize), _font(font),
    _button({position.x, position.y, size.x, size.y})
{
    _colors[Normal] = color.color;
    _colors[Hover] = color.hoverColor;
    _colors[Click] = color.pressedColor;
}

void Indie::Scenes::Button::event()
{
    _btnAction = false;
    if (CheckCollisionPointRec(GetMousePosition(), _button)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) _btnState = Click;
        else _btnState = Hover;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) run();
    } else _btnState = Normal;
}

void Indie::Scenes::Button::display()
{
    Vector2 windowSize = {float(GetScreenWidth()), float(GetScreenHeight())};
    if (_isTextured)
        DrawTexture(_textures[_btnState], _button.x, _button.y, WHITE);
    else
        DrawRectangleRec(_button, _colors[_btnState]);
    _text.setPosition({_button.x + _button.width / 2 - _text.getSize().x / 2,
            _button.y + _button.height / 2 - _text.getSize().y / 2}
    );
    _text.draw();
}

bool Indie::Scenes::Button::getBtnAction() const
{
    return _btnAction;
}

void Indie::Scenes::Button::setPosition(Vector2 pos)
{
    _button.x = pos.x;
    _button.y = pos.y;
}
