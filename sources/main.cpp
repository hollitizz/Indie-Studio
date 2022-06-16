/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include "Bomberman.hpp"

int main(int ac, char **av, char **env)
{
    if (!env[0]) return 84;
    Indie::Bomberman game;

    game.loop();
    return 0;
}