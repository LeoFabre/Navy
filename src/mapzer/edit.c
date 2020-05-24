/*
** EPITECH PROJECT, 2019
** all functions used to setup the map
** File description:
** switches
*/

#include "navy.h"

int get_x_coord(char stupid)
{
    switch (stupid) {
    case 'A' :
        return 2;
    case 'B' :
        return 4;
    case 'C' :
        return 6;
    case 'D' :
        return 8;
    case 'E' :
        return 10;
    case 'F' :
        return 12;
    case 'G' :
        return 14;
    case 'H':
        return 16;
    }
    return -1;
}

int get_y_coord(char stupid)
{
    switch (stupid) {
    case '1' :
        return 2;
    case '2' :
        return 3;
    case '3' :
        return 4;
    case '4' :
        return 5;
    case '5' :
        return 6;
    case '6' :
        return 7;
    case '7' :
        return 8;
    case '8':
        return 9;
    }
    return -1;
}

int edit_y(char *str, char **map2d)
{
    int x_coord = get_x_coord(str[2]);
    int y_coord1 = get_y_coord(str[3]);
    int y_coord2 = get_y_coord(str[6]);
    for (int i = y_coord1; i <= y_coord2; i++)
        map2d[i][x_coord] = str[0];
    return 0;
}

int edit_x(char *str, char **map2d)
{
    int x_coord1 = get_x_coord(str[2]);
    int x_coord2 = get_x_coord(str[5]);
    int y_coord = get_y_coord(str[3]);
    for (int i = x_coord1; i <= x_coord2; i += 2)
        map2d[y_coord][i] = str[0];
    return 0;
}

int edit(char *str, char **map2d)
{
    if (str[2] == str[5] && str[3] < str[6])
        edit_y(str, map2d);
    else if (str[2] < str[5] && str[3] == str[6])
        edit_x(str, map2d);
    else
        return 84;
    return 0;
}