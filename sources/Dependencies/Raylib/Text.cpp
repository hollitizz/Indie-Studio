/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Text
*/

#include "Text.hpp"

Raylib::Text::Text(std::string text, Color color)
{
    _font = GetFontDefault();
    _size = 50;
    _pos = {0, 0};
    _color = color;
    _text = text;
}

Raylib::Text::Text(std::string text, ::Font font, Color color)
{
    _font = font;
    _size = 50;
    _pos = {0, 0};
    _color = color;
    _text = text;
}

Raylib::Text::~Text()
{
}

void Raylib::Text::setPosition(Vector2 pos, int size)
{
    _pos = pos;
    _size = size;
}

Vector2 Raylib::Text::getSize() const
{
    return MeasureTextEx(_font, _text.c_str(), _size, 10);
}

void Raylib::Text::draw() const
{
    DrawTextEx(_font, _text.c_str(), _pos, _size, 10, _color);
}
