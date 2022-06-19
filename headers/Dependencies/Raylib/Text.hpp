/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** Text
*/

#pragma once

#include "raylib.h"
#include <string>

namespace Raylib {
    class Text {
        public:
            Text(std::string text, Color color, int fontSize);
            Text(std::string text, ::Font font, Color color, int fontSize);
            Text(const Text&) = delete;
            ~Text();
            void setPosition(Vector2 pos);
            void setText(std::string text);
            void setColor(Color color);
            std::string getText();
            size_t getTextSize() const;
            Vector2 getSize() const;
            void draw() const;
        protected:
        private:
            ::Font _font;
            int _size;
            Vector2 _pos;
            Color _color;
            std::string _text;
    };
};