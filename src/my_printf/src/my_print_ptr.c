/*
** EPITECH PROJECT, 2019
** my_print_ptr
** File description:
** Print an variable adress
*/

#include "../proto.h"
#include <stdio.h>

int ptr_hex_low(unsigned long long nb)
{
    if (nb == 10)
        nb = 97;
    if (nb == 11)
        nb = 98;
    if (nb == 12)
        nb = 99;
    if (nb == 13)
        nb = 100;
    if (nb == 14)
        nb = 101;
    if (nb == 15)
        nb = 102;
    return (nb);
}

int my_print_ptr(unsigned long long nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    } else if (nb > 9 && nb < 16) {
        my_putchar(ptr_hex_low(nb));
    } else {
        my_print_ptr(nb / 16);
        if ((nb % 16) < 9)
            my_putchar((nb % 16) + 48);
        else if (nb % 16 > 9 && nb % 16 < 16)
            my_putchar(ptr_hex_low(nb % 16));
    }
    return (0);
}
