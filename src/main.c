/*
** EPITECH PROJECT, 2018
** main
** File description:
** Leo Fabre
*/

#include "navy.h"

int launch_game(snavy_t *navy, int argc, char **argv)
{
    if (argc == 2) {
        if (check_errors(argv[1]) == 1)
            return (84);
        start_server(argv[1], navy);
    } else if (argc == 3) {
        if (check_errors(argv[2]) == 1)
            return (84);
        start_client(navy, my_array_to_int(argv[1]), argv[2]);
    }
    return (0);
}

int main(int argc, char **argv)
{
    struct sigaction act = {0};
    snavy_t *navy = malloc(sizeof(snavy_t));

    if (!navy || argc != 2 && argc != 3)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0) {
        print_help();
        return (0);
    }
    init_and_sig(&act);
    if (launch_game(navy, argc, argv) == 84)
        return (84);
    return (value_return(navy));
}
