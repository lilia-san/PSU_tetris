/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display character
*/

#include "../proto.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
