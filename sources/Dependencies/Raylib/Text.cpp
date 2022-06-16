/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Text
*/

#include "Text.hpp"

Raylib::Text::Text(std::string text, Color color, int fontSize)
{
    _font = GetFontDefault();
    _size = fontSize;
    _pos = {0, 0};
    _color = color;
    _text = text;
}

Raylib::Text::Text(std::string text, ::Font font, Color color, int fontSize)
{
    _font = font;
    _size = fontSize;
    _pos = {0, 0};
    _color = color;
    _text = text;
}

Raylib::Text::~Text()
{
}

void Raylib::Text::setPosition(Vector2 pos)
{
    _pos = pos;
}

void Raylib::Text::setText(std::string text)
{
    _text = text;
}

void Raylib::Text::setColor(Color color)
{}

Vector2 Raylib::Text::getSize() const
{
    return MeasureTextEx(_font, _text.c_str(), _size, 10);
}

std::string Raylib::Text::getText()
{
    return _text;
}

size_t Raylib::Text::getTextSize() const
{
    return _text.size();
}

void Raylib::Text::draw() const
{
    DrawTextEx(_font, _text.c_str(), _pos, _size, 10, _color);
}