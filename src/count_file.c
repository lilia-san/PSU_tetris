/*
** EPITECH PROJECT, 2020
** count_file
** File description:
** Count the file in directory
*/

#include "../include/tetris.h"

int count_file(char *path)
{
    int count = 0;
    DIR *dir;
    struct dirent *tmp;

    dir = opendir(path);
    if (dir == NULL)
        exit(84);
    while ((tmp = readdir(dir)) != NULL)
        if (tmp->d_name[0] != '.')
            count++;
    closedir(dir);
    return (count);
}
