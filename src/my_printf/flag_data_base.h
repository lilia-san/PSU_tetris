/*
** EPITECH PROJECT, 2019
** flag_data_base_struct
** File description:
** Struct of regiter of flags
*/

typedef struct flag_data_base
{
    char c;
    void (*ptr)(va_list);
}flag_t;

int flag_use(char *str, va_list ap);
