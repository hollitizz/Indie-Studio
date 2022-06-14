/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Clock
*/

#include "Clock.hpp"
#include <iostream>
#include <cmath>

Raylib::Clock::Clock(float timeInSeconds)
{
    _framesAtCreation = GetTime();
    _timeInSeconds = timeInSeconds;
}

Raylib::Clock::~Clock()
{
}

bool Raylib::Clock::isClockFinished() const
{
    return GetTime() - _framesAtCreation >= _timeInSeconds + (60 / GetFPS()) - 1;
}
