/*
** EPITECH PROJECT, 2020
** init_mino
** File description:
** init tetrimino table
*/

#include "../include/tetris.h"

int init_mino(tetris_t *game)
{
    char **info;
    char **data;
    char **files = dir_rd("./tetriminos");

    game->piece = malloc(sizeof(mino_t) * game->nb_tetrimino);
    for (int i = 0; i < game->nb_tetrimino; i++)
        game->piece[i].name = my_strcpy(files[i]);
    for (int i = 0; i < game->nb_tetrimino; i++) {
        data = check_file(my_strcat("./tetriminos/", game->piece[i].name));
        if (data == NULL) {
            game->piece[i].valid = false;
            continue;
        }
        game->piece[i].valid = true;
        info = parse_info(data[0], ' ');
        game->piece[i].size.x = my_getnbr(info[0]);
        game->piece[i].size.y = my_getnbr(info[1]);
        game->piece[i].color = my_getnbr(info[2]);
        game->piece[i].mino = cpy_tab(1, data);
    }
}