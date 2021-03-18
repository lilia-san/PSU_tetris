/*
** EPITECH PROJECT, 2019
** my_put_hex
** File description:
** Convert number to hexadecimal base
*/

#include "../proto.h"

int letter_hex_up(int nb)
{
    if (nb == 10)
        nb = 65;
    if (nb == 11)
        nb = 66;
    if (nb == 12)
        nb = 67;
    if (nb == 13)
        nb = 68;
    if (nb == 14)
        nb = 69;
    if (nb == 15)
        nb = 70;
    return (nb);
}

int my_put_hex_up(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    } else if (nb > 9 && nb < 16) {
        my_putchar(letter_hex_up(nb));
    } else {
        my_put_hex_up(nb / 16);
        if ((nb % 16) < 9)
            my_putchar((nb % 16) + 48);
        else if ((nb % 16) > 9 && (nb % 16) < 16)
            my_putchar(letter_hex_up(nb % 16));
    }
    return (0);
}
