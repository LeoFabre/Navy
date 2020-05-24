/*
** EPITECH PROJECT, 2018
** process_packet
** File description:
** Leo Fabre
*/
#include "navy.h"

int handle_pkts(char const *packet, siginfo_t const *info, int *mode)
{
    if (my_strcmp(packet, "1111111100") == 0 && *mode == 0) {
        connection.connected_pid = info->si_pid;
        return (0);
    }
    if (my_strcmp(packet, "1010101000") == 0 && *mode == 0) {
        connection.received_connection_answer = 1;
        return (0);
    }
    if (my_strcmp(packet, "1111111111") == 0 && *mode == 0) {
        *mode = 1;
        connection.last_get_string = "";
        return (0);
    }
    return 1;
}

void hit_mgr(int hitresult)
{
    connection.i_hit_miss++;
    connection.last_hit_res = hitresult;
}

void hit_to_mgr(char const *packet, int mode)
{
    if (my_strcmp(packet, "1100000000") == 0 && mode == 0) {
        hit_mgr(0);
    }
    if (my_strcmp(packet, "1000000000") == 0 && mode == 0) {
        hit_mgr(1);
    }
}

int process_packet(char *packet, siginfo_t *info)
{
    static int mode = 0;

    if (mode == 1) {
        get_string(packet, &mode);
        return (0);
    }
    if (handle_pkts(packet, info, &mode) == 0)
        return (0);
    hit_to_mgr(packet, mode);
    return (0);
}
