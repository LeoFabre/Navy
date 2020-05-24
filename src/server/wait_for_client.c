/*
** EPITECH PROJECT, 2018
** wait_for_client
** File description:
** Leo Fabre
*/
#include "navy.h"

void wait_for_client(void)
{
    my_printf("waiting for enemy connection...\n");
    while (connection.connected_pid == 0) {
        usleep(1000);
    }
    usleep(1000);
    send_packet("1010101000", connection.connected_pid);
    my_printf("enemy connected\n\n");
}