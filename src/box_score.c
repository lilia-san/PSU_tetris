/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

void score_box(tetris_t *tetris)
{
    int nscore = 0, nhigh = 1, nline = 2, nlevel = tetris->level, ntime = 4;
    char *score = int_in_char(nscore);
    char * high_score = int_in_char(nhigh);
    char *line = int_in_char(nline);
    char *level = int_in_char(nlevel);
    char *time = int_in_char(ntime);

    mvaddstr(29 , 20, score);
    mvaddstr(30 , 20, high_score);
    mvaddstr(31 , 20, line);
    mvaddstr(32 , 20, level);
    for (int i = 0; i < 100; i++) {
        mvaddstr(35 , 20, time);
        ntime++;
    }
}

void next_box(t_tetrimino *tetrimino)
{
    time_t clock;
    srandom((unsigned) time(&clock));
    int n = rand() % 8;
    int c = (rand() % 6) + 1;
    while (n == 1 || n == 5 || n == 7)
        n = rand() % 8;
    int i = 0, y = 6, x = 71;
    for (; tetrimino->piece[n][i] != '\0'; i++, x++) {
        move(y, x);
        attron(COLOR_PAIR(c));
        if (tetrimino->piece[n][i] == '*' || tetrimino->piece[n][i] == ' ')
            addch(tetrimino->piece[n][i]);
        else {
            i++;
            y++, x = 71;
            if (tetrimino->piece[n][i] == '*' || tetrimino->piece[n][i] == ' ')
                mvaddch(y, x, tetrimino->piece[n][i]);
        }attroff(COLOR_PAIR(c));
    }
}
