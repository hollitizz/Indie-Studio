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

        void clearBackground();
        void clearBackground(Color color);
        void beginDrawing();
        void endDrawing();
        void start3D();
        void end3D();

        void setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
        Camera getCamera() const;
        void updateCamera();

        void drawText(const std::string &text, Vector2 pos, float scale, Color color);
        void drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, Color color);
        void drawTextEx(Font font, const std::string &text, Vector2 pos, float scale, float spacing, Color color);
        Vector2 measureTextEx(Font, std::string text, int scale) const;
        Vector2 measureTextEx(Font, std::string text, int scale, int spacing) const;
        void drawFps(const Vector2 &pos);
        void drawTexture(Texture2D texture, Vector2 position);
        void drawModel(Model model, Vector3 position);
        void drawRectangleRec(Rectangle &rec, Color color);
        Font getDefaultFont() const;

        Vector2 getScreenSize() const;
        char getPressedCharacter() const;
        int getKeyPressed() const;
        bool isKeyPressed(int button) const;
        bool isKeyReleased(int button) const;

        bool isMousePressed() const;
        bool isMouseDown() const;
        bool isMouseReleased() const;
        bool checkCollisionPointRec(Rectangle &rec, const Vector2 &point) const;
        Vector2 getMousePosition() const;

        Image loadImage(std::string fileName) const;
        Texture2D loadTexture(const std::string path);
        Texture2D loadTextureFromImage(Image image);
        Mesh genMeshCubicmap(Image image, Vector3 cubeSize);
        Model loadModelFromMesh(Mesh mesh, Texture2D mapTexture);
        std::vector<Color> loadImageColors(Image image);
        void unloadModel(Model model);
        void unloadImage(Image image);
        void unloadTexture(Texture2D texture);
    protected:
    private:
        Camera _camera;
        std::pair<int, int> _screenSize;
};
