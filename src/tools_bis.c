/*
** EPITECH PROJECT, 2024
** PSU_navy_2019
** File description:
** Created by Enzo Ventura
*/

#include "navy.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
}