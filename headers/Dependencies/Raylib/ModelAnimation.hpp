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
                std::string modelRunAnimationPath
            );
            ModelAnimation(const ModelAnimation&) = delete;
            ~ModelAnimation();
            ::ModelAnimation *getAnimation() const;
            int getFrameCounter() const;
            void setAnimation(std::string);
            void setFrameCounter(int value);
        protected:
        private:
            int _animationFrameCounter = 0;
            unsigned int _animCount = 0;
            ::ModelAnimation *_modelAnimation;
    };
};
