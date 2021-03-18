/*
** EPITECH PROJECT, 2020
** chech_keys
** File description:
** Check if two key have same value.
*/

#include "../include/tetris.h"

void check_key(tetris_t game)
{
    if (game.key.drop == game.key.left || game.key.drop == game.key.pause
    || game.key.drop == game.key.quit || game.key.drop == game.key.right
    || game.key.drop == game.key.turn || game.key.left == game.key.pause
    || game.key.left == game.key.quit || game.key.left == game.key.right
    || game.key.left == game.key.turn || game.key.pause == game.key.quit
    || game.key.pause == game.key.right || game.key.pause == game.key.turn
    || game.key.quit == game.key.right || game.key.quit == game.key.turn
    || game.key.right == game.key.turn)
        exit (84);
}
