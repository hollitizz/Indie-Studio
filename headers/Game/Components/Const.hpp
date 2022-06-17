/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** gameConst
*/

#include <array>
#include <map>
#include <string>

#define TIME_BEFORE_EXPLOSION 3
#define TIME_BEFORE_VANISH 4

const std::array<Vector2, 4> PLAYER_STARTS_POSITION = {
    Vector2{-6, -7},
    Vector2{6, 5},
    Vector2{6, -7},
    Vector2{-6, 5}
};

const std::array<std::array<KeyboardKey, 5>, 4> PLAYER_KEY_MAP = {
    std::array<KeyboardKey, 5> {KEY_Q, KEY_W, KEY_S, KEY_A, KEY_D},
    std::array<KeyboardKey, 5> {KEY_SLASH, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT},
    std::array<KeyboardKey, 5> {KEY_R, KEY_T, KEY_G, KEY_F, KEY_H},
    std::array<KeyboardKey, 5> {KEY_U, KEY_I, KEY_K, KEY_J, KEY_L}
};

#define LIGHTRED       CLITERAL(Color){ 255, 102, 102, 255 }
#define LIGHTGREEN       CLITERAL(Color){ 118, 255, 102, 255 }

const std::array<Color, 4> COLORS = {
    LIGHTGREEN,
    LIGHTRED,
    GOLD,
    SKYBLUE
};

enum ROTATION_SIDE {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum ANIMATIONS_LIST {
    RUN,
    IDLE
};

static std::map<ROTATION_SIDE, Vector3> ROTATION = {
    {UP, Vector3{0, 30, 30}},
    {DOWN, Vector3{1, 0, 0}},
    {LEFT, Vector3{385, 435, 170}},
    {RIGHT, Vector3{0, 120, 105}}
};

static std::map<ROTATION_SIDE, float> ROTATION_ANGLE = {
    {UP, 200},
    {DOWN, -90},
    {LEFT, 270},
    {RIGHT, 120}
};

static std::map<ANIMATIONS_LIST, std::string> ANIMATIONS = {
    {RUN, "assets/Game/Player/models/playerRunAnimation.iqm"},
    {IDLE, "assets/Game/Player/models/playerIdleAnimation.iqm"}
};
