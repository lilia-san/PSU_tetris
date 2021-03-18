/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp an my_strncmp implementation
*/

#include "../include/tetris.h"

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            continue;
        else
            return (0);
    }
    return (1);
}

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i])
            continue;
        else
            return (0);
    }
    return (1);
}
