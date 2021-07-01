/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

#define put_sign(nb) (nb >= 0) ? my_putchar('+') : 0
#define skip_param(c) (c == '#' || c == '+') ? 1 : 0

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char *str, char *delims);
char *my_strdup(char const *src);
void my_exception(void);
int check_alphanum(char c);
int count_words(char const *str);
int word_length(char const *str, int word_index);
void my_swap_int_array(int *number1, int *number2);
int my_put_nbr_base_int(int nb, char const *base);
int my_put_nbr_base_long(long nb, char *base);
int convert_decimal_to_octal(int dec_nb);
int convert_decimal_to_binary(int dec_nb);
char *convertDecimalToHexa(int dec_nb);
int my_put_adress(long long nb);
int my_get_number_after_commas(float nb);
double float_modulo(double nb, double mod);
int my_switch_numbers(char *str, va_list args, int i);
int my_switch_alpha(char *str, va_list args, int i);
int my_switch_hexbin(char *str, va_list args, int i);
int my_switch_hash(char *str, va_list args, int i);
void my_put_unsigned(unsigned int nb);
void my_put_ascii(int nb);
void my_putstr_np(char *str);
void put_zeros(char *str, int i);
void my_printf(char *str, ...);

#endif /* !MY_H_ */