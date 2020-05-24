/*
** EPITECH PROJECT, 2018
** connect_to_server
** File description:
** Leo Fabre
*/
#include "navy.h"

void wait_for_server_response(void)
{
    while (connection.received_connection_answer != 1)
        usleep(10);
}

void connect_to_server(int server_pid)
{
    send_packet("1111111100", server_pid);
    connection.connected_pid = server_pid;
    wait_for_server_response();
    my_printf("succesfully connected\n\n");
}