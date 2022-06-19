/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Choice
*/

#include <iostream>
#include "Choice.hpp"
#include "raylib.h"

Indie::Scenes::Choice::Choice(std::vector<std::string> choices, Indie::Game &game, State &state, Vector2 size, Vector2 position, int fontSize, Font font,
    Texture2D texture, Texture2D hoverTexture, Texture2D pressedTexture):
    _Game(game), _State(state), _isTextured(true),
    _button({position.x, position.y, size.x, size.y}),
    _text("", BLACK, fontSize),
    _choices(choices)
{
    _textures[Normal] = texture;
    _textures[Hover] = hoverTexture;
    _textures[Click] = pressedTexture;

    _choice = 0;
    _text.setText(_choices[_choice]);
}

Indie::Scenes::Choice::Choice(std::vector<std::string> choices, Indie::Game &game, State &state, Vector2 size, Vector2 position, int fontSize, Font font,
    ChoiceColor color = {BLUE, ORANGE, RED}):
    _Game(game), _State(state), _isTextured(false),
    _button({position.x, position.y, size.x, size.y}),
    _text("", BLACK, fontSize),
    _choices(choices)
{
    _colors[Normal] = color.color;
    _colors[Hover] = color.hoverColor;
    _colors[Click] = color.pressedColor;

    _choice = 0;
    _text.setText(_choices[_choice]);
}

void Indie::Scenes::Choice::event()
{
    _btnAction = false;
    if (CheckCollisionPointRec(GetMousePosition(), _button)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) _btnState = Click;
        else _btnState = Hover;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) run();
    } else _btnState = Normal;
}

void Indie::Scenes::Choice::display()
{
    Vector2 windowSize = {float(GetScreenWidth()), float(GetScreenHeight())};
    if (_isTextured)
        DrawTexture(_textures[_btnState], _button.x, _button.y, WHITE);
    else
        DrawRectangleRec(_button, _colors[_btnState]);
    if (_choice >= _Game.getNbPlayers()) {
        _choice = _Game.getNbPlayers() - 1;
        _text.setText(_choices[_choice]);
    }
    _text.setPosition({_button.x + _button.width / 2 - _text.getSize().x / 2, _button.y + _button.height / 2 - _text.getSize().y / 2});
    _text.draw();
}

int Indie::Scenes::Choice::getChoice() const
{
    return _choice;
}

bool Indie::Scenes::Choice::getBtnAction() const
{
    return _btnAction;
}

void Indie::Scenes::Choice::setPosition(Vector2 pos)
{
    _button.x = pos.x;
    _button.y = pos.y;
}

void Indie::Scenes::Choice::run()
{
    _btnAction = true;
    if (_choice == _choices.size() - 1 ||
        _choice == _Game.getNbPlayers() - 1)
        _choice = 0;
    else
        _choice++;
    _text.setText(_choices[_choice]);
    std::cerr << "Choice" << std::endl;
}