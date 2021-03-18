/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

int my_game(tetris_t *tetris)
{
    t_map *map = (t_map *)malloc(sizeof(*map));
    t_tetrimino *tetrimino = (t_tetrimino *)malloc(sizeof(*tetrimino));
    t_game *game = (t_game *)malloc(sizeof(*game));

    map = open_map(map);
    if (map->error == 84)
        return (84);
    if (malloc_tab(tetrimino, "./tetriminos") == NULL || tetrimino->error == 84)
        return (84);
    if (fill_tab(tetrimino, "./tetriminos") == NULL)
        return (84);
    my_game_board(map, tetrimino, tetris, game);
    return (0);
}

int main(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    if (ac == 2 && my_strcmp(av[1], "--help")) {
        usage(av[0]);
        return (0);
    }
    init(tetris);
    init_mino(tetris);
    get_info(ac, av, tetris);
    check_key(*tetris);
    if (tetris->debug == true)
        debug(*tetris);
    if (my_game(tetris) == 84)
        return (84);
    return (0);
}
