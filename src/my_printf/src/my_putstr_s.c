/*
** EPITECH PROJECT, 2019
** my_putstr_S
** File description:
** Displays octal value of no printable character
*/

#include "../proto.h"

int my_putstr_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            if (str[i] >= 127)
                my_put_oct(str[i]);
            else if (str[i] <= 7) {
                my_putstr("\\00");
                my_put_oct(str[i]);
            } else {
                my_putstr("\\0");
                my_put_oct(str[i]);
            }
        }
    }
    return (0);
}
