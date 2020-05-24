/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include <navy.h>
#include <my.h>
#include "stdlib.h"

t_list *init_list(void)
{
    t_list *list = malloc(sizeof(t_list));

    list->first = NULL;
    list->last = NULL;
    return list;
}

void print_list(t_list *list)
{
    t_elem *current = list->first;

    if (list->first != NULL && list->last != NULL) {
        for (; current != NULL; current = current->next) {
            my_put_nbr(current->value);
            if (current->next != NULL)
                my_printf(" -> ");
        }
    } else
        my_printf("!!List is empty!!");
    my_putchar('\n');
}

int list_len(t_list *list)
{
    t_elem *current = list->first;
    int i = 0;

    if (list->first != NULL && list->last != NULL)
        for (; current != NULL; i++, current = current->next);
    return i;
}