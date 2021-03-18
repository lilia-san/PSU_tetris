/*
** EPITECH PROJECT, 2020
** chech_file
** File description:
** Check if navy file is valid
*/

#include "../include/tetris.h"

static char **malloc_info(char *path, FILE *file)
{
    int i = 0;
    int rd = 0;
    size_t size = 7;
    int nb_line = count_line(path);
    char **info = malloc(sizeof(char *) * (nb_line + 1));

    if (nb_line == 0)
        return (NULL);
    while (i < nb_line) {
        info[i] = malloc(sizeof(char) * size);
        rd = getline(&info[i], &size, file);
        info[i][rd - 1] = '\0';
        i++;
    }
    info[nb_line] = NULL;
    return (info);
}

static int valid_info(char **tab)
{
    char c;

    for (int i = 0; tab[0][i] != '\0'; i++)
        if ((tab[0][i] < '0' || tab[0][i] > '9') && tab[0][i] != ' ')
            return (-1);
    char **data = parse_info(tab[0], ' ');
    if (tab_len(data) != 3)
        return (-1);
    for (int i = 0; data[i] != NULL; i++)
        if (my_getnbr(data[i]) <= 0)
            return (-1);
    for (int i = 1; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            c = tab[i][j];
            if (c != '*' && c != ' ')
                return (-1);
        }
    }
    return (0);
}

char **check_file(char *filepath)
{
    int i = 0;
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return (NULL);
    char **data = malloc_info(filepath, file);
    if (data == NULL)
        return (NULL);
    if (valid_info(data) != 0)
        return (NULL);
    fclose(file);
    return (data);
}
