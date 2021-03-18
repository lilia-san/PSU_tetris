/*
** EPITECH PROJECT, 2019
** openfile
** File description:
** Open a file
*/

#include "../include/tetris.h"

char *openfile(char *filepath)
{
    int fd = 0;
    int sz = 0;
    char *buff = NULL;
    struct stat stbuff;

    stat(filepath, &stbuff);
    fd = open(filepath, O_RDONLY);
    sz = stbuff.st_size;
    if (sz == 0)
        return (NULL);
    buff = malloc(sizeof(char) * (sz + 1));
    read(fd, buff, sz);
    return (buff);
}
