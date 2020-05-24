/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Task02
*/

#ifndef MY_H_
#define MY_H_
#include "my_printf.h"
#ifndef READ_SIZE
#define READ_SIZE   10
#endif

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char  const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strcat_char(char *src, char dest);
char *my_strncat(char *dest, char const *src, int nb);
int my_strlenalphab(char const *str);
int my_array_to_int(char *str);
int my_strtol(char *str, char **endptr);
int my_put_unsigned(unsigned int nb);
void swap_elem(int *array, int index1, int index2);
char **my_str_to_word_array(char *str, char *characs, int start);
char *my_strdup(char const *str);

#endif
