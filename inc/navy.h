/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Leo Fabre
*/
#ifndef NAVY_H
#define NAVY_H
#include <malloc.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "map_storage.h"
#include "connexion.h"
#include "structures.h"
#include "lists.h"

connection_t connection;
void end_print(snavy_t *);
int get_x_coord(char);
void print_client(snavy_t *navy, char *);
void print_server(snavy_t *navy, char *filepath);
char *itb(int);
char *format(char *);
char bti(char *);
void game_loop(snavy_t *);
int check_win(snavy_t *);
int start_server(char *, snavy_t *);
void connect_to_server(int);
int send_packet(char *packet, int dest_pid);
void c_to_packet(char);
void send_str(char *);
void get_string(char *, int *);
void wait_for_client(void);
void wait_for_server_response(void);
void sig_handlr(int , siginfo_t *, void *);
void bit_receiver(int, siginfo_t *);
int check_src(siginfo_t *);
int process_packet(char *, siginfo_t *);
int _coord(char);
int get_y_coord(char);
int edit_y(char *, char **);
int edit_x(char *, char **);
int edit(char *, char **);
char **map2df(void);
char **four_strings(char *);
int start_client(snavy_t *, int, char *);
void print_help(void);
char *my_strcat_char(char *, char);
void print_maps(char **, char **);
char *get_next_line(int fd);
char one_char(int fd);
void init_and_sig(struct sigaction *act);
connection_t init_connection(void);
int value_return(snavy_t const *navy);
void attack_s(snavy_t *navy, int current_hit);
void defend_c(snavy_t *navy, int current_line);
void attack_c(snavy_t *navy, int current_hit);
void defend_s(snavy_t *navy, int current_line);
//errors
int check_errors(char *filepath);
int check_nb_x(char **map);
int fill_errors(char *filepath);
int check_size(char **config_file);
int check_nb_boat(char **config_file);
int check_size_boat(char **config_file);
int check_diagonal(char **config_file);
int check_argument(char **config_file);
int list_len(t_list *list);
int diff_number(char **config_file, int i);
int diff_char(char **config_file, int i);
int check_same_num(char *line);
int check_same_letter(char *line);
void free_tab(char **tab);
//tools
char **file_in_darray(int fd);

#endif