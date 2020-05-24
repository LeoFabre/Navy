/*
** EPITECH PROJECT, 2024
** PSU_navy_2018
** File description:
** Created by Leo Fabre
*/
#ifndef PSU_NAVY_2018_LISTS_H
#define PSU_NAVY_2018_LISTS_H

typedef struct s_elem t_elem;

typedef struct s_elem {
    int value;
    t_elem *next;
    t_elem *prev;
} t_elem;

typedef struct s_list {
    t_elem *first;
    t_elem *last;
} t_list;

#endif //PSU_NAVY_2018_LISTS_H
