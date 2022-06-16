/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** State
*/

#pragma once

#include <string>
#include "Type.hpp"

namespace Indie
{
    class State {
        public:
            State();
            ~State() = default;
            void setWinner(std::string winner);
            void setScene(Indie::Scenes::Type scene);
            void setGameScene(Indie::Scenes::Type scene);
            std::string getWinner() const;
            Indie::Scenes::Type getScene() const;
            Indie::Scenes::Type getGameScene() const;
            bool IsGamePaused() const;
        private:
            std::string _winner;
            Indie::Scenes::Type _sceneCurrent;
            Indie::Scenes::Type _sceneGameCurrent;
    };
}

