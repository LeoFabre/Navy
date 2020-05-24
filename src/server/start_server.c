/*
** EPITECH PROJECT, 2018
** start_server
** File description:
** Leo Fabre
*/
#include "navy.h"

int start_server(char *map, snavy_t *navy)
{
    connection.is_server = 1;
    connection.is_client = 0;
    my_printf("my_pid: %d\n", getpid());
    wait_for_client();
    print_server(navy, map);
    game_loop(navy);
    return 0;
}