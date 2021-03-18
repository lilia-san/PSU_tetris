/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

t_map *open_map(t_map *map)
{

    map->title = open_read("./title");
    map->score = open_read("./score");
    if (map->title == NULL || map->score == NULL)
        map->error = 84;
    return (map);
}

void colored(void)
{
    if (has_colors() == FALSE) {
        endwin();
        my_putstr("Your terminal doesn't support color\n");
        exit(84);
    }
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void draw_map(int col, int ligne)
{
    int ln = 11, cn = 33, i = 0;
    mvaddch(11, 32, '+');
    for (int k = 0; k < col; k++, cn++)
        mvaddch(ln, cn, '-');
    mvaddch(ln, cn, '+');
    ln = ln + 1;
    for (; i < ligne; i++, ln++) {
        mvaddch(ln, 32, '|');
        for (int k = 0, cn = 33; k < col; k++, cn++)
            mvaddch(ln, cn, ' ');
        mvaddch(ln, cn, '|');
    }
    mvaddch(ln, 32, '+');
    for (i = 0, cn = 33; i < col; i++, cn++)
        mvaddch(ln, cn, '-');
    mvaddch(ln, cn, '+');
}

void draw_elementry(t_map *map, int col, int ligne)
{
    colored();
    attron(COLOR_PAIR(6));
    printw(map->title);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(1));
    printw(map->score);
    attroff(COLOR_PAIR(1));
    draw_map(col, ligne);
}
