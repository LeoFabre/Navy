/*
** EPITECH PROJECT, 2019
** print_server.c
** File description:
** koolzer
*/

#include "navy.h"

void print_server(snavy_t *navy, char *filepath)
{
    int fd2 = open("../mapzer/map", O_RDONLY);
    int fd = open("pos1", O_RDONLY);

    navy->coord = malloc(sizeof(char *) * 5);
    navy->pos = malloc(sizeof(char) * 33);
    navy->map1d = malloc(sizeof(char) * 185);
    read(fd, navy->pos, 32);
    read(fd2, navy->map1d, 184);
    navy->coord = four_strings(filepath);
    navy->s_map2d = map2df();
    navy->c_map2d = map2df();
    for (int i = 0; i < 4; i++)
        edit(navy->coord[i], navy->s_map2d);
    print_maps(navy->s_map2d, navy->c_map2d);
}