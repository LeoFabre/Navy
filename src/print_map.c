/*
** EPITECH PROJECT, 2019
** print map
** File description:
** yeh
*/

#include "navy.h"

void print_maps(char **map1, char **map2)
{
    my_printf("my positions:\n");
    for (int i = 0; map1[i] != NULL; i++)
        my_printf("%s\n", map1[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0; map2[i] != NULL; i++)
        my_printf("%s\n", map2[i]);
    my_printf("\n");
}