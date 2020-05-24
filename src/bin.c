/*
** EPITECH PROJECT, 2019
** binary functions
** File description:
** kool bruh
*/

#include "navy.h"

char *itb(int i)
{
    int g = 1;
    char *str;
    int c = 1;

    if (i < 0)
        return (0);
    while (i > g) {
        g = g * 2;
        c++;
    }
    str = malloc(sizeof(char) * (c + 1));
    str[c] = '\0';
    for (int f = 0; f != c; f++) {
        if (g <= i) {
            str[f] = '1';
            i -= g;
        } else
            str[f] = '0';
        g = g / 2;
    }
    return format(str);
}

char bti(char *str)
{
    int temp = 0;

    for (int i = 0; i <= 7; i++) {
        temp *= 2;
        if (str[i] == '1')
            temp++;
    }
    return (temp);
}

char *format(char *str)
{
    while (my_strlen(str) < 8)
        str = my_strcat("0", str);
    str = my_strcat(str, "00");
    return str;
}