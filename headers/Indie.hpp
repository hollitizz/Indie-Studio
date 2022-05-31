/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Scenes
*/

#pragma once

#include <memory>
#include <map>

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
                virtual void display() = 0;
                virtual void test() = 0;
            private:
        };
        class AScene : public IScene {
            public:
                AScene() = default;
                ~AScene() = default;
                virtual void display();
                virtual void test() = 0;
            private:
        };
        class SMenu : public AScene {
            public:
                SMenu();
                ~SMenu();
                void test() override;
            private:
        };
        class SGame : public AScene {
            public:
                SGame();
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
    };
};