/*
** EPITECH PROJECT, 2020
** count_line
** File description:
** count the number of line
*/

#include "../include/tetris.h"

int count_line(char *path)
{
    int count = 0;
    char *str = openfile(path);

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    free(str);
    return (count);
}
