/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-enzo1.vallet
** File description:
** DrawScope
*/

#pragma once
#include "Raylib.hpp"

class DrawScope {
    public:
        DrawScope(Raylib &raylib): _Raylib(raylib)
        {
            _Raylib.beginDrawing();
            _Raylib.clearBackground();
        };
        ~DrawScope()
        {
            _Raylib.endDrawing();
        };
    private:
        Raylib &_Raylib;
};

class Draw3DScope {
    public:
        Draw3DScope(Raylib &raylib): _Raylib(raylib)
        {
            _Raylib.beginDrawing();
            _Raylib.clearBackground();
        };
        ~Draw3DScope()
        {
            _Raylib.endDrawing();
        };
    private:
        Raylib &_Raylib;
};