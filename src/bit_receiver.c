/*
** EPITECH PROJECT, 2018
** bit_receiver
** File description:
** Leo Fabre
*/
#include <malloc.h>
#include "navy.h"

int check_src(siginfo_t *info)
{
    if (info->si_pid == connection.connected_pid)
        return (0);
    else
        return (84);
}

void bit_receiver(int bit, siginfo_t *info)
{
    static char *temp = "\0";

    if (bit == 0) {
        if (connection.connected_pid == 0 ||
            info->si_pid == connection.connected_pid) {
            temp = my_strcat(temp, "0");
        }
    } else if (bit == 1) {
        if (connection.connected_pid == 0 ||
            info->si_pid == connection.connected_pid) {
            temp = my_strcat(temp, "1");
        }
    }
    if (my_strlen(temp) >= 10) {
        process_packet(temp, info);
        temp = "\0";
    }
}