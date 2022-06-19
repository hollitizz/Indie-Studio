/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Music
*/

#include "Music.hpp"
#include <iostream>

Raylib::Music::Music(std::string path) : _music(LoadMusicStream(path.c_str()))
{
    std::cerr << "Music Init" << std::endl;
}

Raylib::Music::~Music()
{
    StopMusicStream(_music);
    UnloadMusicStream(_music);
    std::cerr << "Music Destroy" << std::endl;
}

void Raylib::Music::setMusic(std::string path)
{
    StopMusicStream(_music);
    UnloadMusicStream(_music);
    _music = LoadMusicStream(path.c_str());
    PlayMusicStream(_music);
}

void Raylib::Music::start()
{
    _isMuted = false;
    PlayMusicStream(_music);
}

void Raylib::Music::stop()
{
    _isMuted = true;
    StopMusicStream(_music);
}

void Raylib::Music::update()
{
    if (!_isMuted)
        UpdateMusicStream(_music);
}

bool Raylib::Music::getMuted()
{
    return _isMuted;
}