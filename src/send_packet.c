/*
** EPITECH PROJECT, 2018
** send_packet
** File description:
** Leo Fabre
*/
#include "navy.h"

void send_str(char *str)
{
    int i = 0;

    send_packet("1111111111", connection.connected_pid);
    while (i <= my_strlen(str)) {
        c_to_packet(str[i]);
        i++;
        usleep(1000);
    }
}

void c_to_packet(char c)
{
    char *result = itb(c);

    send_packet(result, connection.connected_pid);
}

int send_packet(char *packet, int dest_pid)
{
    int i = 0;

    if (my_strlen(packet) != 10) {
        return (84);
    }
    while (packet[i] != '\0') {
        if (packet[i] == '0') {
            kill(dest_pid, SIGUSR1);
            usleep(10000);
        } else if (packet[i] == '1') {
            kill(dest_pid, SIGUSR2);
            usleep(10000);
        } else {
            return (84);
        }
        i++;
    }
    return (0);
}