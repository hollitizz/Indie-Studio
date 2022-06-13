/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** gameConst
*/

#include <array>
#include "Raylib.hpp"

const std::array<Vector2, 4> PLAYER_STARTS_POSITION = {
    Vector2{-6, -7},
    Vector2{6, -7},
    Vector2{6, 5},
    Vector2{-6, 5}
};

const std::array<std::array<KeyboardKey, 5>, 4> PLAYER_KEY_MAP = {
    std::array<KeyboardKey, 5> {KEY_Q, KEY_W, KEY_S, KEY_A, KEY_D},
    std::array<KeyboardKey, 5> {KEY_R, KEY_T, KEY_G, KEY_F, KEY_H},
    std::array<KeyboardKey, 5> {KEY_SLASH, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT},
    std::array<KeyboardKey, 5> {KEY_U, KEY_I, KEY_K, KEY_J, KEY_L}
};