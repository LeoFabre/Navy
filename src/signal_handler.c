/*
** EPITECH PROJECT, 2018
** signal_handler
** File description:
** Leo Fabre
*/
#include "navy.h"

void sig_handlr(int num, siginfo_t *info, void *etoile __attribute__((unused)))
{
    if (num == SIGUSR1)
        bit_receiver(0, info);
    else if (num == SIGUSR2)
        bit_receiver(1, info);
}