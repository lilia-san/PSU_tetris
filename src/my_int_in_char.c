/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

char *int_in_char(int nb)
{
    char *str = NULL;
    str = malloc(sizeof(char) * 5);
    if (str == NULL)
        return (NULL);
    if (nb <= 9) {
        str[0] = nb + '0';
        str[1] = '\0';
    }
    else {
        str[0] = (nb / 10) + '0';
        str[1] = (nb % 10) + '0';
        str[2] = '\0';
    }
    return (str);
}
