/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** ModelAnimation
*/

#include "ModelAnimation.hpp"
#include <iostream>

Raylib::ModelAnimation::ModelAnimation(
    std::string modelPath, std::string modelTexturePath, std::string modelRunAnimationPath
): _model(modelPath, modelTexturePath)
{
    std::cerr << "ModelAnimation Init" << std::endl;
    _animationCount = 0;
    _modelAnimation = LoadModelAnimations(modelRunAnimationPath.c_str(), 0)[0];
}

Raylib::ModelAnimation::~ModelAnimation()
{
    std::cerr << "ModelAnimation Destroy" << std::endl;
    UnloadModelAnimations(&_modelAnimation, 0);
}
