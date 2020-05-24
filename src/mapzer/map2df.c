/*
** EPITECH PROJECT, 2019
** get base map
** File description:
** map2df
*/
#include "navy.h"

char **map2df(void)
{
    char *map1d = malloc(sizeof(char) * 185);
    char **map2d;
    int fd2 = open("map", O_RDONLY);
    int ci = 0;

    read(fd2, map1d, 184);
    map2d = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 10; i++) {
        map2d[i] = malloc(sizeof(char) * 19);
        for (int j = 0; j < 19 && map1d[ci] != '\n'; j++) {
            map2d[i][j] = map1d[ci];
            ci++;
        }
        map2d[i][19] = '\0';
        ci++;
    }
    map2d[10] = NULL;
    return (map2d);
}