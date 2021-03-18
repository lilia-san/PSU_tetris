/*
** EPITECH PROJECT, 2020
** parse_path
** File description:
** Parse path and return it in array
*/

#include "../include/tetris.h"

int find_next(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}

int info_nb(char *str, char c)
{
    int i = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return (count + 1);
}

char **parse_info(char *str, char c)
{
    int a = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (info_nb(str, c) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && (i == 0 || str[i - 1] == c)) {
            if (find_next(&str[i], c) == -1) {
                tab[a] = cut_cpy(str, i, my_strlen(str));
                break;
            } else {
                tab[a] = cut_cpy(str, i, i + find_next(&str[i], c));
                a++;
            }
        } else
            continue;
    }
    tab[info_nb(str, c)] = NULL;
    return (tab);
}
