/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displays a number
*/

#include "../proto.h"

int my_put_nbr_u(unsigned int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr_u(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
