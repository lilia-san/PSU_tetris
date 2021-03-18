/*
** EPITECH PROJECT, 2020
** debug
** File description:
** Display debug information
*/

#include "../include/tetris.h"

void print_key(tetris_t game)
{
    my_printf("Key Left : ");
    display_key(game.key.left);
    my_printf("Key Right : ");
    display_key(game.key.right);
    my_printf("Key Turn : ");
    display_key(game.key.turn);
    my_printf("Key Drop : ");
    display_key(game.key.drop);
    my_printf("Key Quit : ");
    display_key(game.key.quit);
    my_printf("Key Pause : ");
    display_key(game.key.pause);
}

void print_other(tetris_t game)
{
    if (game.next == true)
        my_printf("Next : Yes\n");
    else
        my_printf("Next : No\n");
    my_printf("Level : %d\n", game.level);
    my_printf("Size : %d*%d\n", game.map_size.y, game.map_size.x);
    my_printf("Tetriminos : %d\n", game.nb_tetrimino);
}

int print_mino(mino_t piece)
{
    my_printf("Tetriminos : Name ");
    for (int i = 0; piece.name[i] != '.'; i++)
        my_printf("%c", piece.name[i]);
    my_printf(" : ");
    if (piece.valid == false) {
        my_printf("Error\n");
        return (0);
    }
    my_printf("Size %d*%d : ", piece.size.x, piece.size.y);
    my_printf("Color %d :\n", piece.color);
    for (int i = 0; piece.mino[i] != NULL; i++)
        my_printf("%s\n", piece.mino[i]);
    return (0);
}

void print_pieces(tetris_t game)
{
    for (int i = 0; i < game.nb_tetrimino; i++)
        print_mino(game.piece[i]);
}

int debug(tetris_t game)
{
    int i = 0;
    char c;

    my_printf("*** DEBUG MODE ***\n");
    print_key(game);
    print_other(game);
    print_pieces(game);
    my_printf("Press any key to start Tetris\n");
    read(0, &c, 256);
    return (0);
}