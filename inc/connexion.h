/*
** EPITECH PROJECT, 2018
** connexion
** File description:
** Leo Fabre
*/

typedef struct connection_s{
    int connected_pid;
    char *last_get_string;
    int received_connection_answer;
    int is_client;
    int is_server;
    int i_get_string;
    int i_hit_miss;
    int last_hit_res;
} connection_t;