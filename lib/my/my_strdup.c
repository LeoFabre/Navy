/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Enzo Ventura
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * ((my_strlen(str) + 1)));

    dest = my_strcpy(dest, str);
    return (dest);
}