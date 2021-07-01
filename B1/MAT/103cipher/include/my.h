/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_pow(int nb, int p);
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
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
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
void my_put_error(char *message);
char *check_type_int(char *str, va_list args);
char *check_type_char(char *str, va_list args);
char *check_type_base(char *str, va_list args);
char *check_type_other(char *str, va_list args);
int my_putnbr_base_int(int number, char const *base);
int my_put_address(long long nbr);
int my_putnbr_base_long(long number, char *base);
unsigned int my_put_unsigned_nbr(unsigned int nbr);
char *check_for_hashtag(char *str, va_list args);
void check_for_plus(char *str, va_list args);
void my_printf(char const *str, ...);
void my_putstr_nonprintable(char const *str);
int my_show_word_array(char * const *tab);

#endif