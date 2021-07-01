/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** bsprintf
*/

#include <stdarg.h>
#ifndef MY_H_
#define MY_H_

int sum_numbers (int n, ...);
int sum_strings_length (int n, ...);
void disp_stdarg (char *s, ...);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_put_error(char *message);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
void my_put_float_with_dec(float nbr, int nb_after_comma);
int my_pow(int nb, int p);
int my_getnbr(char const *str);
char *check_type_int(char *str, va_list args);
char *check_type_char(char *str, va_list args);
char *check_type_base(char *str, va_list args);
char *check_type_other(char *str, va_list args);
int give_octal_value(int res);
int give_binary_value(int res);
int my_putnbr_base_int(int number, char const *base);
int my_put_address(long long nbr);
int my_putnbr_base_long(long number, char *base);
unsigned int my_put_unsigned_nbr(unsigned int nbr);
char *check_for_hashtag(char *str, va_list args);
void my_printf(char const *str, ...);
void my_putstr_nonprintable(char const *str);
char *my_strcpy(char *dest, char const *src);
void check_for_plus(char *str, va_list args);

#endif