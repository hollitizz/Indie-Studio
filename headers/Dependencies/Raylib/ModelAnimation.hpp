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
            ::ModelAnimation *getAnimation() const;
            int getFrameCounter() const;
            void setAnimation(std::string);
            void setFrameCounter(int value);
            void update();
        protected:
        private:
            int _animationFrameCounter = 0;
            unsigned int _animCount = 0;
            Raylib::Model _model;
            ::ModelAnimation *_modelAnimation;
            Raylib::Texture2D _texture;
    };
};
