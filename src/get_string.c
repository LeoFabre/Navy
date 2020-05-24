/*
** EPITECH PROJECT, 2018
** get_string
** File description:
** Leo Fabre
*/
#include "navy.h"

void get_string(char *packet, int *mode)
{
    static char *temp = "\0";
    char packet_value = bti(packet);

    if (my_strcmp(packet, "0000000000") == 0) {
        *mode = 0;
    }
    temp = my_strcat_char(temp, packet_value);
    if (my_strlen(temp) >= 2) {
        connection.last_get_string = my_strdup(temp);
        connection.i_get_string++;
        free(temp);
        temp = "\0";
    }
}