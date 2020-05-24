/*
** EPITECH PROJECT, 2019
** end_print
** File description:
** yeh
*/

#include "navy.h"

void end_print(snavy_t *navy)
{
    if (connection.is_client)
        print_maps(navy->c_map2d, navy->s_map2d);
    else
        print_maps(navy->s_map2d, navy->c_map2d);
    if (navy->game_status == 1)
        my_printf("I won\n");
    if (navy->game_status == -1)
        my_printf("Enemy won\n");
}