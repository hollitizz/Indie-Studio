/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** ModelAnimation
*/

#include "ModelAnimation.hpp"
#include <iostream>

Raylib::ModelAnimation::ModelAnimation(
    std::string modelRunAnimationPath
)
{
    std::cerr << "ModelAnimation Init" << std::endl;
    _animationFrameCounter = 0;
    _modelAnimation = LoadModelAnimations(modelRunAnimationPath.c_str(), &_animCount);
}

Raylib::ModelAnimation::~ModelAnimation()
{
    std::cerr << "ModelAnimation Destroy" << std::endl;
    for (int i = 0; i < _animCount; i += 1) {
        UnloadModelAnimations(_modelAnimation, 0);
    }
}

::ModelAnimation *Raylib::ModelAnimation::getAnimation() const
{
    return (_modelAnimation);
}

int Raylib::ModelAnimation::getFrameCounter() const
{
    return (_animationFrameCounter);
}

void Raylib::ModelAnimation::setAnimation(std::string animationPath)
{
    _modelAnimation = LoadModelAnimations(animationPath.c_str(), &_animCount);
}

void Raylib::ModelAnimation::setFrameCounter(int value)
{
    _animationFrameCounter = value;
}
