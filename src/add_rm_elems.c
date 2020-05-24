/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/
#include <navy.h>
#include <my.h>
#include "stdlib.h"

void add_to_end(t_list *list, int value)
{
    t_elem *new = malloc(sizeof(t_elem));

    new->value = value;
    new->next = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->prev = NULL;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
}

void add_to_start(t_list *list, int value)
{
    t_elem *new = malloc(sizeof(t_elem));

    new->value = value;
    new->prev = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else {
        new->next = list->first;
        list->first->prev = new;
        list->first = new;
    }
}

void rm_first(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->first = list->first->next;
        free(list->first->prev);
        list->first->prev = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void rm_last(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void free_list(t_list *list)
{
    while (list->first != NULL)
        rm_first(list);
    free(list);
}
