/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Leo Fabre
*/
#include "navy.h"

int check_argument(char **config_file)
{
    for (int i = 0; config_file[i]; i++) {
        if ((config_file[i][2] < 'A' || config_file[i][2] > 'H') ||
            (config_file[i][5] < 'A' || config_file[i][5] > 'H') ||
            (config_file[i][3] < '1' || config_file[i][3] > '8') ||
            (config_file[i][6] < '1' || config_file[i][6] > '8')) {
            return (1);
        }
    }
    return (0);
}

int check_diagonal(char **config_file)
{
    for (int i = 0; config_file[i]; i++) {
        if (check_same_num(config_file[i]) == 0 &&
            check_same_letter(config_file[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

int check_size_boat(char **config_file)
{
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;

    for (int i = 0; config_file[i]; i++) {
        if (config_file[i][0] == '2')
            two++;
        if (config_file[i][0] == '3')
            three++;
        if (config_file[i][0] == '4')
            four++;
        if (config_file[i][0] == '5')
            five++;
    }
    if (two != 1 || three != 1 || four != 1 || five != 1)
        return (1);
    return (0);
}

int check_nb_boat(char **config_file)
{
    int count = 0;
    int i;

    for (i = 0; config_file[i]; i++) {
        for (int j = 0; config_file[i][j]; j++) {
            if (config_file[i][j] == ':')
                count++;
        }
    }
    if (count != 8 || i != 4)
        return (1);
    return (0);
}