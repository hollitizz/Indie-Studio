/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Music
*/

#pragma once

#include <string>
#include "raylib.h"

namespace Raylib {
    class Music {
        public:
            Music(std::string path);
            ~Music();
            void setMusic(std::string path);
            void start();
            void stop();
            void update();
            bool getMuted();
        protected:
        private:
            ::Music _music;
            bool _isMuted = false;
    };
}
