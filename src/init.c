/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

connection_t init_connection(void)
{
    connection.connected_pid = 0;
    connection.last_get_string = "\0";
    connection.received_connection_answer = 0;
    connection.is_client = 0;
    connection.is_server = 0;
    connection.i_get_string = 0;
    connection.i_hit_miss = 0;
    return connection;
}

void init_and_sig(struct sigaction *act)
{
    connection = init_connection();
    (*act).sa_sigaction = &(sig_handlr);
    (*act).sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, act, 0);
    sigaction(SIGUSR2, act, 0);
}