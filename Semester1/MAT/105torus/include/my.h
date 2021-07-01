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
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
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
int my_isneg(int nb);
char *my_itoa(int nb);
int my_put_nbr(int nb);
char *my_strdup(char const *src);
void my_swap_str(char **a, char **b);
void my_swap_int(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str, int neg);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strcat_char(char *dest, char src);
char *my_strncat(char *dest, char const *src, int nb);
void my_exception(void);
void swap_numbers(int *int_1, int *int_2);
int check_alphanum(char c);
char **my_str_to_word_array(char const *str);
int count_words(const char *tmp);
int word_len(char const *str);
void print_arr(char **arr);
int add(int nb1, int nb2);
int subs(int nb1, int nb2);
int multi(int nb1, int nb2);
int divi(int nb1, int nb2);
int modu(int nb1, int nb2);
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
char **sort_tab_alpha(char **tab, int *list_maj);
char **put_maj(char **tab, int *list_maj);
int *make_list_maj(char **tab);
void my_put_tab(char **tab, char *string_between);
static int check_solution(char **argv, double xn);
static int recursive(char **argv, double x0, double x1, int nb_dec);
int bisection(char **argv);
double my_func(char **argv, double x);

#endif