/*
** EPITECH PROJECT, 2020
** cut_cpy
** File description:
** Cut and duplicate string and returns it
*/

#include "../include/tetris.h"

char *cut_cpy(char *str, int n1, int n2)
{
    int n = n2 - n1;
    char *cpy = malloc(sizeof(char) * (n + 1));

    for (int i = n1, j = 0; i <= n2; i++, j++)
        cpy[j] = str[i];
    cpy[n] = '\0';
    return (cpy);
}
