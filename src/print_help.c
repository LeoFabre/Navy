/*
** EPITECH PROJECT, 2018
** print_help
** File description:
** Leo Fabre
*/
#include "navy.h"

void print_help(void)
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd player. pid of the first ");
    my_printf("player.\n");
    my_printf("\tnavy_positions: file representing the positions ");
    my_printf("of the ships.\n");
}