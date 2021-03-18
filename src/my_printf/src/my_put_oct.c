/*
** EPITECH PROJECT, 2019
** my_put_oct
** File description:
** Convert a number to octal
*/

#include "../proto.h"

int my_put_oct(int nb)
{
    if (nb >= 0 && nb <= 7) {
        my_putchar(nb + '0');
    } else if (nb < 0) {
        my_putchar('-');
        my_put_oct(nb * (-1));
    } else {
        my_put_oct(nb / 8);
        my_putchar((nb % 8) + 48);
    }
    return (0);
}
