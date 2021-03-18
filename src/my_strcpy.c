/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** return the copy of string
*/

#include "../include/tetris.h"

char *my_strcpy(char *src)
{
    int size = my_strlen(src);
    char *dest = malloc(sizeof(char) * (size + 1));

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[size] = '\0';
    return (dest);
}
