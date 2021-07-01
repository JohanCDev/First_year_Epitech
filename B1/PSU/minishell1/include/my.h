/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>

#define int_is_printable(c) (c > 31 && c < 127) ? 1 : 0
#define put_plus(nb) nb >= 0 ? my_putchar('+') : 0
#define skip_after_hash(str) (str == '#' || str == '+') ? str++ : 0
#define is_upper(c) (c >= 'A' && c <= 'Z') ? 1 : 0
#define is_num(c) (c >= '0' && c <= '9') ? 1 : 0

void my_putchar(char c);
char *my_itoa(int nb);
int my_put_nbr(int nb);
char *my_strdup(char const *src);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strcat_char(char *dest, char src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
int count_words(const char *tmp);
int word_len(char const *str);
void print_arr(char **arr);
int my_put_error(char *message);
char *int_to_str(int i);
char *check_type_int(char *str, va_list args);
char *check_type_char(char *str, va_list args);
char *check_type_base(char *str, va_list args);
void check_type_other(char *str, va_list args);
int my_putnbr_base_int(int number, char const *base);
int my_put_address(long long nbr);
int my_putnbr_base_long(long number, char *base);
unsigned int my_put_unsigned_nbr(unsigned int nbr);
char *check_for_hashtag(char *str, va_list args);
void check_for_plus(char *str, va_list args);
void my_printf(char const *str, ...);
void my_putstr_nonprintable(char const *str);
void my_put_tab(char **tab, char *string_between);


#endif