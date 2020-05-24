/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Leo Fabre
*/
#include "navy.h"
#include "structures.h"


void send_atk_s(snavy_t const *navy, int current_hit,
    const int coordsxy[2], char const *pos)
{
    char *coords = malloc(sizeof(char) * 3);

    coords[0] = pos[0];
    coords[1] = pos[1];
    coords[2] = '\0';
    send_str(coords);
    my_printf("%s: ", coords);
    while (current_hit != connection.i_hit_miss)
        usleep(1000);
    if (connection.last_hit_res == 0) {
        my_printf("hit\n\n");
        navy->c_map2d[coordsxy[1]][coordsxy[0]] = 'x';
    } else {
        my_printf("missed\n\n");
        navy->c_map2d[coordsxy[1]][coordsxy[0]] = 'o';
    }
}

void attack_s(snavy_t *navy, int current_hit)
{
    int coords[2];
    char *pos = malloc(sizeof(char) * 3);

    my_printf("attack: ");
    while (read(0, pos, 3) != 3);
    pos[2] = '\0';
    coords[0] = get_x_coord(pos[0]);
    coords[1] = get_y_coord(pos[1]);
    if (coords[0] == -1 || coords[1] == -1) {
        my_printf("wrong position\n");
        free(pos);
        attack_s(navy, current_hit);
        return;
    }
    send_atk_s(navy, current_hit, coords, pos);
}

void defend_s(snavy_t *navy, int current_line)
{
    int xpos;
    int ypos;
    my_printf("waiting for enemy's attack...\n");
    while (current_line != connection.i_get_string) {
        usleep(1000);
    }
    xpos = get_x_coord(connection.last_get_string[0]);
    ypos = get_y_coord(connection.last_get_string[1]);
    if (navy->s_map2d[ypos][xpos] != '.' && navy->s_map2d[ypos][xpos] != 'o') {
        my_printf("%s: hit\n\n", connection.last_get_string);
        navy->s_map2d[ypos][xpos] = 'x';
        send_packet("1100000000", connection.connected_pid);
    } else {
        my_printf("%s: missed\n\n", connection.last_get_string);
        navy->s_map2d[ypos][xpos] = 'o';
        send_packet("1000000000", connection.connected_pid);
    }
}
