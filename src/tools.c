/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

int diff_number(char **config_file, int i)
{
    int size = config_file[i][0];
    int nb1 = config_file[i][3];
    int nb2 = config_file[i][6];
    int diff = nb2 - nb1;

    if ((diff + 1) != size)
        return (1);
    return (0);
}

int diff_char(char **config_file, int i)
{
    char char1 = config_file[i][2];
    char char2 = config_file[i][5];

    if ((char1 - char2) != (config_file[i][0] + 1))
        return (1);
    return (0);
}

int check_same_num(char *line)
{
    if (line[3] == line[6])
        return (1);
    return (0);
}

int check_same_letter(char *line)
{
    if (line[2] == line[5])
        return (1);
    return (0);
}
char **file_in_darray(int fd)
{
    char *s = get_next_line(fd);
    char **array = NULL;
    int i = 0;

    array = malloc(sizeof(char *) * (4 + 1));
    while (s) {
        array[i] = my_strdup(s);
        i++;
        free(s);
        s = get_next_line(fd);
    }
    array[i] = NULL;
    return (array);
}