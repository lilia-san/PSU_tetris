/*
** EPITECH PROJECT, 2020
** init
** File description:
** init game struct
*/

#include "../include/tetris.h"

void init(tetris_t *game)
{
    game->level = 1;
    game->debug = 0;
    game->next = true;
    game->map_size.x = 10;
    game->map_size.y = 20;
    game->key.left = KEY_LEFT;
    game->key.right = KEY_RIGHT;
    game->key.turn = KEY_UP;
    game->key.drop = KEY_DOWN;
    game->key.quit = 'q';
    game->key.pause = ' ';
    game->nb_tetrimino = count_file("./tetriminos");
}
