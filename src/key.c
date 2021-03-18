/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include <string.h>
#include "../include/tetris.h"

int heigh_tetrimino(char *str)
{
    int h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            h = h + 1;
    }
    return (h);
}

void clear_tetrimino(t_tetrimino *tetrimino, int col, int y)
{
    int x = 33;
    while (mvinch(y, x) != '|') {
        mvaddch(y, x, ' ');
        x++;
    }
}

void going_down(t_tetrimino *tetrimino, tetris_t *tetris, int y, t_game *game)
{
    int h = heigh_tetrimino(tetrimino->piece[game->n]);
    if ((y + h) < 32) {
        clear_tetrimino(tetrimino, tetris->map_size.y, y);
        y = y + 1;
        show_tetrimino(tetrimino, tetris->map_size.x, y, game);
    }
}

void move_tetrimino(tetris_t *tetris, t_tetrimino *tetrimino, t_game *game)
{
    int y = 12, key = 0;
    game = have_random_stuff(game);
    show_tetrimino(tetrimino, tetris->map_size.x, y, game);
    while (key = getch()) {
        switch (key)
        {
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
        case KEY_DOWN:
            going_down(tetrimino, tetris, y, game);
            y = y + 1;
            break;
        case 32:
            break;
        }
        if (y >= 32) {
            y = 12;
            game = have_random_stuff(game);
        }
    }
}
