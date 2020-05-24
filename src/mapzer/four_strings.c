/*
** EPITECH PROJECT, 2019
** gets 4 coordanotes from file
** File description:
** filename is geven as paramenter
*/

#include "navy.h"

char **four_strings(char *filepath)
{
    char *pos = malloc(sizeof(char *) * 33);
    int fd = open(filepath, O_RDONLY);
    char **ship = malloc(sizeof(char *) * 5);

    read(fd, pos, 32);
    for (int nc = 0; nc < 4; nc++) {
        ship[nc] = malloc(sizeof(char) * 9);
        for (int i = nc * 8; pos[i] != '\n' && pos[i] != '\0'; i++)
            ship[nc][i % 8] = pos[i];
        ship[nc][7] = '\0';
    }
    ship[4] = NULL;
    return ship;
}