/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Same behavior with printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../flag_data_base.h"
#include "../proto.h"
#include "../ptr.h"

int my_printf(char *str, ...)
{
    int n = my_strlen(str);
    va_list ap;

    va_start(ap, str);
    flag_use(str, ap);
    va_end(ap);
    return (n);
}
