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
            void pause();
            void resume();
            bool isClockFinished() const;
        private:
            bool isPaused = false;
            float _timeInSeconds;
            float _timePaused;
            float _timeAtCreation;
    };
};