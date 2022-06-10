/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** DrawScope
*/

#pragma once
#include "Camera.hpp"

class DrawScope {
    public:
        DrawScope()
        {
            BeginDrawing();
            ClearBackground(WHITE);
        };
        ~DrawScope()
        {
            EndDrawing();
        };
};

class Draw3DScope {
    public:
        Draw3DScope(Raylib::Camera camera)
        {
            BeginMode3D(camera.getCamera());
        };

        ~Draw3DScope()
        {
            EndMode3D();
        };
    private:
};