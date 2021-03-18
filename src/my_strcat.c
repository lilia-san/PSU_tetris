/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concatenate two string
*/

#include "../include/tetris.h"

char *my_strcat(char *dest, char *src)
{
    int n1 = my_strlen(dest);
    int n2 = my_strlen(src);
    char *str = malloc(sizeof(char) * (n1 + n2 + 1));

    for (int i = 0; i < n1; i++)
        str[i] = dest[i];
    for (int i = n1, j = 0; j < n2; i++, j++)
        str[i] = src[j];
    str[n1 + n2] = '\0';
    return (str);
}