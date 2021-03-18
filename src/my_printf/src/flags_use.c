/*
** EPITECH PROJECT, 2019
** flag_use
** File description:
** Recognize flags and display his attribute
*/

#include "../ptr.h"
#include "../proto.h"
#include "../flag_data_base.h"
#include <stdarg.h>
#include <stddef.h>

const flag_t tab[] = {
    {'s', &str},
    {'c', &char_t},
    {'b', &bin},
    {'i', &nbr},
    {'d', &nbr},
    {'+', &nbr},
    {'u', &nbr_u},
    {'%', &char_p},
    {'o', &oct},
    {'m', &err},
    {'p', &ptr},
    {'S', &str_s},
    {'x', &hex_low},
    {'X', &hex_up},
    {'\0', NULL}
};

int flag_use(char *str, va_list ap)
{
    int a = 3;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; tab[j].c != '\0'; j++) {
            if (str[i] == '%' && str[i + 1] == tab[j].c) {
                a = 1;
                if (str[i + 1] == '+')
                    my_putchar('+');
                tab[j].ptr(ap);
                break;
            } else if (str[i - 1] == '%' && str[i] == tab[j].c) {
                a = 0;
                break;
            } else {
                a = 2;
            }
        }
        if (a == 2 && str[i] != '%')
            my_putchar(str[i]);
    } return (0);
}
