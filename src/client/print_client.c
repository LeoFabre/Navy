/*
** EPITECH PROJECT, 2019
** client first print after connection
** File description:
** koolzer
*/

#include "navy.h"

void print_client(snavy_t *snavy, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int fd2 = open("../mapzer/map", O_RDONLY);

    snavy->coord = malloc(sizeof(char *) * 5);
    snavy->pos = malloc(sizeof(char) * 33);
    snavy->map1d = malloc(sizeof(char) * 185);
    read(fd, snavy->pos, 32);
    read(fd2, snavy->map1d, 184);
    snavy->coord = four_strings(filepath);
    snavy->s_map2d = map2df();
    snavy->c_map2d = map2df();
    for (int i = 0; i < 4; i++)
        edit(snavy->coord[i], snavy->c_map2d);
    print_maps(snavy->c_map2d, snavy->s_map2d);
}