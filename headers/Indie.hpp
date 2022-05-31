/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Scenes
*/

#pragma once

#include <memory>
#include <map>
#include "Raylib.hpp"

namespace Indie
{
    namespace Scenes
    {
        enum Type {
            Menu,
            Game,
            Settings,
            Over
        };
        class IScene {
            public:
                virtual ~IScene() = default;
                virtual void start() = 0;
                virtual void stop() = 0;
                virtual void display() = 0;
                virtual void test() = 0;
            private:
        };
        class AScene : public IScene {
            public:
                AScene(Raylib *raylib);
                ~AScene() = default;
                virtual void start();
                virtual void stop();
                virtual void display();
                virtual void test() = 0;
            private:
                Raylib *_Raylib;
        };
        class SMenu : public AScene {
            public:
                SMenu(Raylib *raylib);
                ~SMenu();
                void test() override;
            private:
        };
        class SGame : public AScene {
            public:
                SGame(Raylib *raylib);
                ~SGame();
                void test() override;
            private:
        };
    };
    class Bomberman {
        public:
            Bomberman();
            ~Bomberman();
            void loop();
        private:
            std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
            Indie::Scenes::Type _sceneCurrent;
            Raylib _Raylib;
    };
};