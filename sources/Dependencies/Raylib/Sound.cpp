/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Sound
*/

#include "Sound.hpp"
#include <iostream>

Raylib::Sound::Sound(std::string path) : _sound(LoadSound(path.c_str()))
{
    std::cerr << "Sound Init" << std::endl;
}

Raylib::Sound::~Sound()
{
    UnloadSound(_sound);
    std::cerr << "Sound Destroy" << std::endl;
}

void Raylib::Sound::setMuted()
{
    _isMuted = !_isMuted;
}

bool Raylib::Sound::getMuted()
{
    return _isMuted;
}

void Raylib::Sound::play()
{
    if (!_isMuted)
        PlaySoundMulti(_sound);
}