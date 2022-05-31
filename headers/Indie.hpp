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
    class State;
    namespace Scenes
    {
        enum Type {
            Menu,
            Game,
            Hud,
            Pause,
            Settings,
            Over
        };
        class IScene {
            public:
                virtual ~IScene() = default;
                virtual void start() = 0;
                virtual void stop() = 0;
                virtual void display() = 0;
                virtual void event() = 0;
            private:
        };
        class AScene : public IScene {
            public:
                AScene(Raylib &raylib, Indie::State &state);
                ~AScene() = default;
                virtual void start();
                virtual void stop();
                virtual void display();
                virtual void event() = 0;
            protected:
                Raylib &_Raylib;
                State &_State;
        };
        class SMenu : public AScene {
            public:
                SMenu(Raylib &raylib, Indie::State &state);
                ~SMenu();
                void event() override;
            private:
        };
        class SGame : public AScene {
            public:
                SGame(Raylib &raylib, Indie::State &state);
                ~SGame();
                void event() override;
            private:
                std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
        };
        class SHud : public AScene {
            public:
                SHud(Raylib &raylib, Indie::State &state);
                ~SHud();
                void event() override;
            private:
        };
        class SPause : public AScene {
            public:
                SPause(Raylib &raylib, Indie::State &state);
                ~SPause();
                void event() override;
            private:
        };
        class SSettings : public AScene {
            public:
                SSettings(Raylib &raylib, Indie::State &state);
                ~SSettings();
                void event() override;
            private:
        };
        class SOver : public AScene {
            public:
                SOver(Raylib &raylib, Indie::State &state);
                ~SOver();
                void event() override;
            private:
        };
    };
    class State {
        public:
            State();
            ~State() = default;
            void setScene(Indie::Scenes::Type scene);
            void setGameScene(Indie::Scenes::Type scene);
            Indie::Scenes::Type getScene() const;
            Indie::Scenes::Type getGameScene() const;
        private:
            Indie::Scenes::Type _sceneCurrent;
            Indie::Scenes::Type _sceneGameCurrent;
    };
    class Bomberman {
        public:
            Bomberman();
            ~Bomberman();
            void loop();
        private:
            std::map<Scenes::Type, std::shared_ptr<Scenes::IScene>> _scenes;
            Raylib _Raylib;
            State _State;
    };
};