/*
** EPITECH PROJECT, 2020
** display_key
** File description:
** Displays specials keys
*/

#include "../include/tetris.h"

void display_key(int c)
{
    switch (c) {
    case KEY_UP:
        my_printf("^EOA\n");
        break;
    case KEY_DOWN:
        my_printf("^EOB\n");
        break;
    case KEY_LEFT:
        my_printf("^EOD\n");
        break;
    case KEY_RIGHT:
        my_printf("^EOC\n");
        break;
    case ' ':
        my_printf("(space)\n");
        break;
    default:
        my_printf("%c\n", c);
        break;
    }
}
