/*
** EPITECH PROJECT, 2018
** start_client
** File description:
** Leo Fabre
*/
#include "navy.h"

int start_client(snavy_t *navy, int server_pid, char *map)
{
    connection.is_server = 0;
    connection.is_client = 1;
    my_printf("my_pid: %d\n", getpid());
    connect_to_server(server_pid);
    print_client(navy, map);
    game_loop(navy);
    return 0;
}