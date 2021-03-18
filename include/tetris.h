/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <getopt.h>
#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>

typedef struct game
{
    int n;
    int c;
}t_game;

typedef struct pos
{
    int x;
    int y;
}pos_t;

typedef struct key
{
    int left;
    int right;
    int turn;
    int drop;
    int pause;
    int quit;
}keyt_t;

typedef struct tetrimino
{
    char *name;
    bool valid;
    pos_t size;
    int color;
    char **mino;
}mino_t;

typedef struct tetris
{
    int level;
    pos_t map_size;
    bool next;
    bool debug;
    keyt_t key;
    int nb_tetrimino;
    mino_t *piece;
}tetris_t;

typedef struct t_tetrimino t_tetrimino;
struct t_tetrimino
{
    int wid;
    int hei;
    int color;
    int error;
    char *str;
    char **piece;
};

typedef struct t_map t_map;
struct t_map
{
    int x;
    int y;
    char *title;
    char *score;
    char **tab;
    int error;
};

void move_tetrimino(tetris_t *tetris, t_tetrimino *tetrimino, t_game *game);
void show_tetrimino(t_tetrimino *tetrimino, int col, int y, t_game *game);
void next_box(t_tetrimino *tetrimino);
void score_box(tetris_t *tetris);
char *int_in_char(int nb);
t_game *have_random_stuff(t_game *game);
int my_strlen(char const *str);
void colored();
void draw_elementry(t_map *map, int col, int ligne);
void my_putchar(char c);
int my_putstr(char const *str);
void my_game_board(t_map *map, t_tetrimino *tetrimino, tetris_t *tetris,
t_game *game);
t_map *open_map(t_map *map);
char *open_read(char *file);
t_tetrimino *stock_stuff(char *buffer, t_tetrimino *tetrimino);
char **fill_tab(t_tetrimino *tetrimino, char *folder);
char **malloc_tab(t_tetrimino *tetrimino, char *folder);
char *read_file(char const *file);
void init(tetris_t *game);
int init_mino(tetris_t *game);
char *read_file(char const *file);
int my_printf(char *str, ...);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *src);
char *my_strcat(char *dest, char *src);
void usage(char *str);
int info_nb(char *str, char c);
int tab_len(char **tab);
char *cut_cpy(char *str, int n1, int n2);
char **cpy_tab(int i, char **map);
char **parse_info(char *str, char c);
int my_getnbr(char const *str);
void good_key(char *str);
char **good_size(char *str);
void good_level(char *str);
void get_info(int ac, char **av, tetris_t *game);
void check_key(tetris_t game);
int debug(tetris_t game);
int count_file(char *path);
char **dir_rd(char *name);
char *openfile(char *filepath);
int count_line(char *path);
char **check_file(char *filepath);
void display_key(int c);

#endif
