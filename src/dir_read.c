/*
** EPITECH PROJECT, 2020
** current_read
** File description:
** Display the name of all the element of the current directory
*/

#include <string.h>
#include "../include/tetris.h"

void swap_name(char **files, int i, int j)
{
    char *tmp;

    tmp = my_strcpy(files[i]);
    files[i] = my_strcpy(files[j]);
    files[j] = my_strcpy(tmp);
}

int check_greater(char *str1, char *str2)
{
    int n = 0;

    for (int i = 0; str1[i] != '.' && str2[i] != '.'; i++) {
        if (str1[i] > str2[i])
            return (1);
        else if (n < 0);
            return (-1);
    }
    return (0);
}

void new_selection(int i, char *select, char **files, int *index)
{
    for (int j = i + 1; files[j] != NULL; j++) {
        if (check_greater(select, files[j]) != 0) {
            select = my_strcpy(files[j]);
            *index = j;
        }
    }
}

void sort_name(char **files)
{
    int index;
    int len = tab_len(files);
    char *select_str;

    for (int i = 0; i < len - 1; i++) {
        index = i;
        select_str = my_strcpy(files[i]);
        for (int j = i + 1; j < len; j++) {
            if (check_greater(select_str, files[j]) == 1) {
                select_str = my_strcpy(files[j]);
                index = j;
            }
        }
        if (index != i)
            swap_name(files, i, index);
    }
}

char **dir_rd(char *name)
{
    DIR *dir;
    struct dirent *tmp;
    int i = 0;
    int nb = count_file(name);
    char **files = malloc(sizeof(char *) * (nb + 1));

    files[nb] = NULL;
    dir = opendir(name);
    while ((tmp = readdir(dir)) != NULL) {
        if (tmp->d_name[0] != '.') {
            files[i] = my_strcpy(tmp->d_name);
            i++;
        }
    }
    sort_name(files);
    closedir(dir);
    return (files);
}
