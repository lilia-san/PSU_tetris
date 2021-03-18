/*
** EPITECH PROJECT, 2019
** my_put_bin
** File description:
** Convert to binary base
*/

#include "../proto.h"

int my_put_bin(int nb)
{
    if (nb >= 0 && nb <= 1) {
        my_putchar(nb + '0');
    } else if (nb > 1) {
        my_put_bin(nb / 2);
        my_putchar((nb % 2) + 48);
    }
    return (0);
}
