/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** AnimatedModel
*/

#pragma once

#include "Model.hpp"
#include "raylib.h"

namespace Raylib {
    class ModelAnimation {
        public:
            ModelAnimation(
                std::string modelPath, std::string modelTexturePath, std::string modelRunAnimationPath
            );
            ModelAnimation(const ModelAnimation&) = delete;
            ~ModelAnimation();
            void update();
        protected:
        private:
            int _animationCount = 0;
            Raylib::Model _model;
            ::ModelAnimation _modelAnimation;
    };
};
