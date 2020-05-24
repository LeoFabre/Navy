/*
** EPITECH PROJECT, 2019
** game loop
** File description:
** yeh yeh yeh
*/

#include "navy.h"

int client_server_loop(snavy_t *navy, int current_hit,
    int current_string)
{
    if (connection.is_server) {
        attack_s(navy, current_hit);
            if ((navy->game_status = check_win(navy)) != 0)
                return 1;
        defend_s(navy, current_string);
        print_maps(navy->s_map2d, navy->c_map2d);
    } else {
        defend_c(navy, current_string);
            if ((navy->game_status = check_win(navy)) != 0)
                return 1;
        attack_c(navy, current_hit);
        print_maps(navy->c_map2d, navy->s_map2d);
    }
    return 0;
}

void game_loop(snavy_t *navy)
{
    int current_hit = 0;
    int current_string = 0;

    while ((navy->game_status = check_win(navy)) == 0) {
        current_string++;
        current_hit++;
        client_server_loop(navy, current_hit, current_string);
    }
    end_print(navy);
}