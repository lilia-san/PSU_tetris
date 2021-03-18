/*
** EPITECH PROJECT, 2020
** good_value
** File description:
** Verify the command line value
*/

#include "../include/tetris.h"

void good_key(char *str)
{
    if (my_strlen(str) != 1) {
        my_printf("Bad argument.\n");
        exit(84);
    }
}

char **good_size(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != ',') {
            my_printf("Bad argument.\n");
            exit(84);
        }
    if (info_nb(str, ',') != 2) {
        my_printf("Bad argument.\n");
        exit(84);
    }
    char **data = parse_info(str, ',');
    if (tab_len(data) != 2) {
        my_printf("Bad argument.\n");
        exit(84);
    }
    if (my_getnbr(data[0]) <= 0 || my_getnbr(data[1]) <= 0) {
        my_printf("Bad argument.\n");
        exit(84);
    }
    return (data);
}

void good_level(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_printf("Bad argument.\n");
            exit(84);
        }
    if (my_getnbr(str) <= 0) {
        my_printf("Bad argument.\n");
        exit(84);
    }
}
