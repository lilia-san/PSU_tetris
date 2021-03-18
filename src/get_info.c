/*
** EPITECH PROJECT, 2020
** get_info
** File description:
** Use getopt to get info
*/

#include "../include/tetris.h"

void direction_key(int c, tetris_t *game)
{
    switch (c) {
    case 'l':
        good_key(optarg);
        game->key.left = optarg[0];
        break;
    case 'r':
        good_key(optarg);
        game->key.right = optarg[0];
        break;
    case 't':
        good_key(optarg);
        game->key.turn = optarg[0];
        break;
    case 'd':
        good_key(optarg);
        game->key.drop = optarg[0];
        break;
    }
}

void technical_key(int c, tetris_t *game)
{
    char **data;
    switch (c) {
    case 'q':
        good_key(optarg);
        game->key.quit = optarg[0];
        break;
    case 'p':
        good_key(optarg);
        game->key.pause = optarg[0];
        break;
    case 's':
        data = good_size(optarg);
        game->map_size.x = my_getnbr(data[1]);
        game->map_size.y = my_getnbr(data[0]);
        break;
    case 'L':
        good_level(optarg);
        game->level = my_getnbr(optarg);
        break;
    }
}

void other_key(int c, tetris_t *game)
{
    switch (c) {
    case 'w':
        game->next = false;
        break;
    case 'D':
        game->debug = true;
        break;
    case '?':
        exit(84);
        break;
    }
}

void valid_change(int c, tetris_t *game)
{
    direction_key(c, game);
    technical_key(c, game);
    other_key(c, game);
}

void get_info(int ac, char **av, tetris_t *game)
{
    int c, index = 0;
    char *optstr = "L:l:r:t:d:q:p:wD";
    static struct option options[] = {
        {"level", required_argument, 0, 'L'},
        {"key-left", required_argument, 0, 'l'},
        {"key-right", required_argument, 0, 'r'},
        {"key-turn", required_argument, 0, 't'},
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q'},
        {"key-pause", required_argument, 0, 'p'},
        {"map-size", required_argument, 0, 's'},
        {"without-next", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'}, {0, 0, 0, 0}};

    while ((c = getopt_long(ac, av, optstr, options, &index)) != -1) {
        valid_change(c, game);
    }
    if (optind < ac) {
        my_printf("Missing argument.\n");
        exit(84);
    }
}
