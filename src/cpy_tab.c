/*
** EPITECH PROJECT, 2020
** cpy_tab
** File description:
** Copy double table
*/

#include "../include/tetris.h"

char **cpy_tab(int i, char **map)
{
    int j = i;
    int len = tab_len(map);
    char **cpy = malloc(sizeof(char *) * (len + 1 - i));

    while (map[j] != NULL) {
        cpy[j - 1] = my_strcpy(map[j]);
        j++;
    }
    cpy[len - i] = NULL;
    return (cpy);
}
