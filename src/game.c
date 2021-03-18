/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

char *open_read(char *file)
{
    int fd = 0, rd = 0;
    struct stat info;
    char *buffer = NULL;
    fd = open(file, O_RDONLY);
    if (stat(file, &info) != 0)
        return (NULL);
    else {
        buffer = malloc(sizeof(char) * (info.st_size + 1));
        rd = read(fd, buffer, info.st_size);
    }
    if (buffer == NULL)
        return (NULL);
    close(fd);
    return (buffer);
}

t_game *have_random_stuff(t_game *game)
{
    time_t clock;
    srandom((unsigned) time(&clock));
    game->n = (rand() % (8 - 0 + 1)) + 0;
    game->c = (rand() % (7 - 1 + 1)) + 1;
    while (game->n == 1 || game->n == 5 || game->n == 7)
        game->n = (rand() % (8 - 0 + 1)) + 0;
    return (game);
}

void show_tetrimino(t_tetrimino *tetrimino, int col, int k, t_game *game)
{
    int i = 0, y = k, x = 30 + (col / 2);
    for (; tetrimino->piece[game->n][i] != '\0'; i++, x++) {
        move(y, x);
        attron(COLOR_PAIR(game->c));
        if (tetrimino->piece[game->n][i] == '*' ||
        tetrimino->piece[game->n][i] == ' ')
            addch(tetrimino->piece[game->n][i]);
        else {
            i++;
            y++, x = 30 + (col / 2);
            if (tetrimino->piece[game->n][i] == '*' ||
            tetrimino->piece[game->n][i] == ' ')
            mvaddch(y, x, tetrimino->piece[game->n][i]);
        }attroff(COLOR_PAIR(game->c));
    }
}

void my_game_board(t_map *map, t_tetrimino *tetrimino, tetris_t *tetris,
t_game *game)
{
    map->y = 12, map->x = 30 + (tetris->map_size.x / 2);
    initscr();
    curs_set(0);
    draw_elementry(map, tetris->map_size.x, tetris->map_size.y);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    score_box(tetris);
    if (tetris->next == true)
        next_box(tetrimino);
    wrefresh(stdscr);
    move_tetrimino(tetris, tetrimino, game);
    endwin();
}
