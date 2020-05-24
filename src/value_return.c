/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

int value_return(snavy_t const *navy)
{
    if (navy->game_status == 1)
        return 0;
    else if (navy->game_status == -1)
        return 1;
    else
        return 84;
}