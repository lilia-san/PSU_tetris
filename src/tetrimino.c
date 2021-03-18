/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** project
*/

#include "../include/tetris.h"

char **malloc_tab(t_tetrimino *tetrimino, char *folder)
{
    DIR *fd = 0;
    int count = 0;
    char **tab = NULL;
    struct dirent *directory;
    struct stat info;
    fd = opendir(folder);
    if (fd == NULL)
        tetrimino->error = 84;
    while ((directory = readdir(fd)) != NULL)
        count++;
    closedir(fd);
    tetrimino->piece = malloc(sizeof(char *) * (count));
    for (int x = 0; x < count; x++)
        tetrimino->piece[x] = malloc(sizeof(char) * (15));
    if (tetrimino->piece == NULL)
        return (NULL);
    return (tetrimino->piece);
}

char *concat(char *tab, char *folder, char *d_name)
{
    int len = 0;
    int x = 0;
    tab[0] = '\0';
    tab = my_strcat(tab, folder);
    len = my_strlen(tab);
    tab[len] = '/';
    tab[len + 1] = '\0';
    tab =  my_strcat(tab, d_name);
    return (tab);
}

char **fill_tab(t_tetrimino *tetrimino, char *folder)
{
    DIR *fd = 0;
    int i = 0;
    struct dirent *directory;
    fd = opendir(folder);
    if (fd == NULL)
        return (NULL);
    for (;(directory = readdir(fd)) != NULL; i++) {
        if (directory->d_name[0] != '.') {
            tetrimino->piece[i] = open_read(concat(tetrimino->piece[i], folder,
            directory->d_name));
            tetrimino = stock_stuff(tetrimino->piece[i], tetrimino);
            tetrimino->piece[i] = tetrimino->str;
        }
    }
    return (tetrimino->piece);
}

t_tetrimino *error_tetrimino(char *buffer, t_tetrimino *tetrimino)
{
    for (int i = 0; buffer[i] < 6; i++) {
        if ((buffer[i] < '0' || buffer[i] > '9') &&
            buffer[i] != ' ' && buffer[i] != '\n') {
            tetrimino->error = 84;
        }
    }
    return (tetrimino);
}

t_tetrimino *stock_stuff(char *buffer, t_tetrimino *tetrimino)
{
    int k = 0, i = 0;
    tetrimino = error_tetrimino(buffer, tetrimino);
    tetrimino->str = malloc(sizeof(char) * 10);
    tetrimino->wid = buffer[0] - 48;
    tetrimino->hei = buffer[2] - 48;
    tetrimino->color = buffer[4] - 48;
    for (i = 6; buffer[i] != '\0'; i++, k++)
        tetrimino->str[k] = buffer[i];
    for (int h = 0; tetrimino->str[h] != '\0'; h++) {
        if (tetrimino->str[h] != ' ' && tetrimino->str[h] != '*')
            tetrimino->error = 84;
    }
    return (tetrimino);
}
