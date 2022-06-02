/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Button
*/

#include <iostream>
#include "Button.hpp"

Indie::Scenes::Button::Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    _Raylib(raylib), _text(text), _isTextured(true), _fontSize(fontSize), _font(font),
    _button({position.x, position.y, size.x, size.y})
{
    _textures[Normal] = texture;
    _textures[Hover] = hoverTexture;
    _textures[Click] = pressedTexture;
}

Indie::Scenes::Button::Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Color color, Color hoverColor, Color pressedColor):
    _Raylib(raylib), _text(text), _isTextured(false), _fontSize(fontSize), _font(font),
    _button({position.x, position.y, size.x, size.y})
{
    _colors[Normal] = color;
    _colors[Hover] = hoverColor;
    _colors[Click] = pressedColor;
}

Indie::Scenes::Button::Button(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font):
    _Raylib(raylib), _text(text), _isTextured(false), _fontSize(fontSize), _font(font),
    _button({position.x, position.y, size.x, size.y})
{
    _colors[Normal] = BLUE;
    _colors[Hover] = ORANGE;
    _colors[Click] = RED;
}

void Indie::Scenes::Button::event()
{
    if (_Raylib.checkCollisionPointRec(_button, _Raylib.getMousePosition())) {
        if (_Raylib.isMouseDown()) _btnState = Click;
        else _btnState = Hover;
        if (_Raylib.isMouseReleased()) run();
    } else _btnState = Normal;
}

void Indie::Scenes::Button::display()
{
    Vector2 windowSize = _Raylib.getScreenSize();
    Vector2 TextSize = _Raylib.measureTextEx(_font, _text.c_str(), _fontSize);

    if (_isTextured)
        _Raylib.drawTexture(_textures[_btnState], {_button.x, _button.y});
    else
        _Raylib.drawRectangleRec(_button, _colors[_btnState]);

    _Raylib.drawTextEx(
        _font, _text, {
            _button.x + _button.width / 2 - TextSize.x / 2,
            _button.y + _button.height / 2 - TextSize.y / 2
        },
        _fontSize, BLACK
    );
}

Indie::Scenes::BExit::BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(raylib, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BExit::BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Color color, Color hoverColor, Color pressedColor):
    Button(raylib, size, position, text, fontSize, font, color, hoverColor, pressedColor)
{
}

Indie::Scenes::BExit::BExit(Raylib &raylib, Vector2 size, Vector2 position, std::string text, int fontSize, Font font):
    Button(raylib, size, position, text, fontSize, font)
{
}

void Indie::Scenes::BExit::run()
{
    _Raylib.closeWindow();
    std::cout << "Exit Game" << std::endl;
}

Indie::Scenes::BPlay::BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    Button(raylib, size, position, text, fontSize, font, texture, hoverTexture, pressedTexture)
{
}

Indie::Scenes::BPlay::BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font,
    Color color = BLUE, Color hoverColor = ORANGE, Color pressedColor = RED):
    Button(raylib, size, position, text, fontSize, font, color, hoverColor, pressedColor)
{
}

Indie::Scenes::BPlay::BPlay(Raylib &raylib, State &state, Vector2 size, Vector2 position, std::string text, int fontSize, Font font):
    Button(raylib, size, position, text, fontSize, font)
{
}

void Indie::Scenes::BPlay::run()
{
    _Raylib.closeWindow();
    std::cout << "Exit Game" << std::endl;
}