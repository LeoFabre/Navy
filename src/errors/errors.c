/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

int do_checks(char **config_file, char *filepath)
{
    if (config_file == NULL)
        return (1);
    if (check_nb_boat(config_file) == 1)
        return (1);
    if (check_size_boat(config_file) == 1)
        return (1);
    if (check_diagonal(config_file) == 1)
        return (1);
    if (check_argument(config_file) == 1)
        return (1);
    if (check_size(config_file) == 1)
        return (1);
    if (fill_errors(filepath) == 1)
        return (1);
    return (0);
}

int check_errors(char *filepath)
{
    int fd;
    char **config_file = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (1);
    config_file = file_in_darray(fd);
    return (do_checks(config_file, filepath));
}