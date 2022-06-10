/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** State
*/

#pragma once

#include "Type.hpp"

namespace Indie
{
    class State {
        public:
            State();
            ~State() = default;
            void setScene(Indie::Scenes::Type scene);
            void setGameScene(Indie::Scenes::Type scene);
            Indie::Scenes::Type getScene() const;
            Indie::Scenes::Type getGameScene() const;
            void setIsGamePaused(bool isGamePaused);
            bool getIsGamePaused() const;
        private:
            bool _isGamePaused = false;
            Indie::Scenes::Type _sceneCurrent;
            Indie::Scenes::Type _sceneGameCurrent;
    };
}

