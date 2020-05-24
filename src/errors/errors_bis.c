/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

int check_nb_x(char **map)
{
    int x = 0;

    for (int i = 2; map[i]; i++) {
        for (int j = 3; map[i][j]; j++) {
            if (map[i][j] != '.')
                x++;
        }
    }
    if (x != 70)
        return (1);
    return (0);
}

int fill_errors(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int fd2 = open("../mapzer/map", O_RDONLY);
    char **coord = four_strings(filepath);
    char *pos = malloc(sizeof(char) * 33);
    char **map1d = malloc(sizeof(char) * 185);
    char **c_map2d;

    read(fd, pos, 32);
    read(fd2, map1d, 184);
    c_map2d = map2df();
    for (int i = 0; i < 4; i++)
        edit(coord[i], c_map2d);
    if (check_nb_x(c_map2d) == 1) {
        free_tab(coord);
        free_tab(map1d);
        free_tab(c_map2d);
        free(pos);
        return (1);
    }
    return (0);
}

int check_size(char **config_file)
{
    int nb;
    int first;
    int scnd;

    for (int i = 0; config_file[i]; i++) {
        nb = my_getnbr(config_file[i]);
        if (check_same_letter(config_file[i]) == 1) {
            first = config_file[i][3] + 0;
            scnd = config_file[i][6] + 0;
            if (scnd + 1 != (first + nb))
                return (1);
        } else {
            first = config_file[i][2] + 0;
            scnd = config_file[i][5] + 0;
            if ((nb - 1 != (scnd - first)))
                return (1);
        }
    }
    return (0);
}