/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "Indie.hpp"
#include "Raylib.hpp"

int main(int ac, char **av)
{
    Indie::Bomberman game;

    game.loop();
    return 0;
}