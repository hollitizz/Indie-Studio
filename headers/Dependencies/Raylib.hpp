/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Raylib
*/

#pragma once

#include <vector>
#include <string>
#include "raylib.h"

struct RGB
{
    RGB(int red = 255, int green = 255, int blue = 255, int alpha = 255) : r(red), g(green), b(blue), a(alpha) {};
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

class Raylib {
    public:
        Raylib();
        ~Raylib();
        void createWindow(int width, int height, std::string title, size_t fps);
        void closeWindow();
        bool isOpen();

        void setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
        Camera getCamera() const;

        void drawText(const std::string &text, Vector2 pos, float scale, Color color);
        void drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, float spacing, Color color);
        void drawFps(const Vector2 &pos);

        Vector2 getScreenSize() const;
        char getPressedCharacter() const;
        int getKeyPressed() const;
        bool isKeyPressed(int button) const;
        bool isKeyReleased(int button) const;

        bool isMousePressed() const;
        bool isMouseDown() const;
        bool isMouseReleased() const;
        Vector2 getMousePosition() const;

        std::string _test = "base";

    protected:
    private:
        std::pair<int, int> _screenSize;
        Camera _camera;
};
