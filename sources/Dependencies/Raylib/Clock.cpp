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
    _timeAtCreation = GetTime();
    _timeInSeconds = timeInSeconds;
}

Raylib::Clock::~Clock()
{

}

void Raylib::Clock::pause()
{
    isPaused = true;
    _timePaused = GetTime();
}

void Raylib::Clock::resume()
{
    isPaused = false;
    _timeAtCreation = _timeAtCreation + (GetTime() - _timePaused);
}

bool Raylib::Clock::isCPaused() const
{
    return isPaused;
}

bool Raylib::Clock::isClockFinished()
{
    if (isPaused)
        return _isFinished;
    _isFinished = GetTime() - _timeAtCreation >= _timeInSeconds + (60 / GetFPS()) - 1;
    return _isFinished;
}
