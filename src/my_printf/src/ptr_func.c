/*
** EPITECH PROJECT, 2019
** ptr_func
** File description:
** Contains definiton of pointer on function
*/

#include <stdarg.h>
#include "../proto.h"

void (str)(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void (nbr)(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void (char_t)(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void (oct)(va_list ap)
{
    my_put_oct(va_arg(ap, int));
}

void (hex_low)(va_list ap)
{
    my_put_hex_low(va_arg(ap, int));
}

void (hex_up)(va_list ap)
{
    my_put_hex_up(va_arg(ap, int));
}

void (bin)(va_list ap)
{
    my_put_bin(va_arg(ap, int));
}

void (char_p)(va_list ap)
{
    my_putchar('%');
}

void (nbr_u)(va_list ap)
{
    my_put_nbr_u(va_arg(ap, unsigned int));
}

void (err)(va_list ap)
{
    my_putstr("Success");
}

void (str_s)(va_list ap)
{
    my_putstr_s(va_arg(ap, char *));
}

void (ptr)(va_list ap)
{
    my_putstr("0x");
    my_print_ptr((unsigned long long)va_arg(ap, char *));
}
