/*
** EPITECH PROJECT, 2019
** check_win
** File description:
** ta race
*/

#include "navy.h"

int count_hits(char **map)
{
    int res = 0;

    for (int i = 2; i <= 9; i++) {
        for (int j = 2; j <= 16; j += 2) {
            if (map[i][j] == 'x')
                res++;
        }
    }
    return res;
}

int check_win(snavy_t *snavy)
{
    char **my_map;
    char **his_map;
    int hit_count = 0;

    if (connection.is_server == 1) {
        my_map = snavy->s_map2d;
        his_map = snavy->c_map2d;
    } else {
        my_map = snavy->c_map2d;
        his_map = snavy->s_map2d;
    }
    hit_count = count_hits(my_map);
    if (hit_count == 14)
        return -1;
    hit_count = count_hits(his_map);
    if (hit_count == 14)
        return 1;
    return 0;
}
