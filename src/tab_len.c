/*
** EPITECH PROJECT, 2020
** tab_len
** File description:
** Return char ** len
*/

#include "../include/tetris.h"

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}
