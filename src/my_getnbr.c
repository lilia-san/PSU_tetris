/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int r = 1;
    int nb = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            r = r * (-1);
    }
    for ( ; str[i] >= '0' && str[i] <= '9'; i++)
        nb = nb * 10 + (str[i] - '0');
    return (nb * r);
}
