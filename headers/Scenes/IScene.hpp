/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** IScene
*/

#pragma once

namespace Indie
{
    namespace Scenes
    {
        class IScene {
            public:
                virtual ~IScene() = default;
                virtual void start() = 0;
                virtual void stop() = 0;
                virtual void display() = 0;
                virtual void event() = 0;
            private:
        };
    }
}
