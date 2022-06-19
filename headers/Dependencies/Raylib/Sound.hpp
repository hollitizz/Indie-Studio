/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Sound
*/

#pragma once

#include <string>
#include "raylib.h"

namespace Raylib {
    class Sound {
        public:
            Sound(std::string path);
            ~Sound();
            void play();
            void setMuted();
            bool getMuted();
        protected:
        private:
            ::Sound _sound;
            bool _isMuted = false;
    };
}
