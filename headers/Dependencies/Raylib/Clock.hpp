/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Clock
*/

#pragma once

#include "raylib.h"

namespace Raylib {
    class Clock {
        public:
            Clock(float timeInSeconds);
            ~Clock();
            bool isClockFinished() const;
        private:
            float _timeInSeconds;
            float _framesAtCreation;
    };
};