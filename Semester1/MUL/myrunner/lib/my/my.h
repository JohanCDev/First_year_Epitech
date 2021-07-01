/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_put_error(char *message);
int my_strlen(char const *str);
char *my_itoa (int nb);