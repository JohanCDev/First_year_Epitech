/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#define put_plus(nb) nb >= 0 ? my_putchar('+') : 0
#define skip_after_hash(str) (str == '#' || str == '+') ? str++ : 0

/// Print a single char
/// @param c Char to be printed
/// @since 0.0.0
void my_putchar(char c);
/// Check if an int is negative
/// @param nb nb to verify
/// @returns true if nb is negative
/// @since 0.0.0
bool my_isneg(int nb);
/// Transform an int in a string
/// @param nb nb to convert
/// @returns nb in a string
/// @since 0.0.0
char *my_itoa(int nb);
/// print an error message on stderr and return an int
/// @param message Message to be printed
/// @param code Code that will be return
/// @returns Code given
/// @since 0.0.0
int my_put_error(char *message, int code);
/// print an error message on stderr and return a ptr
/// @param message Message to be printed
/// @param code Code that will be return
/// @returns Code given
/// @since 0.0.0
void *my_put_error_ret_ptr(char *message, char *code);
/// Print an int
/// @param nb nb to print
/// @since 0.0.0
int my_put_nbr(int nb);
/// Duplicate a string into an other by allocating memory
/// @param src String to Duplicate
/// @returns NULL if an error occurs or the string duplicated
/// @since 0.0.0
char *my_strdup(char const *src);
/// Swap two strings
/// @param a Address of the first string
/// @param b Address of the second string
/// @since 0.0.0
void my_swap_str(char **a, char **b);
/// Swap two number
/// @param a Address of the first number
/// @param b Address of the second number
/// @since 0.0.0
void my_swap_int(int *a, int *b);
/// Print a string
/// @param str String to print
/// @since 0.0.0
int my_putstr(char const *str);
/// Get the length of a string
/// @param str Str to test
/// @returns Length of the string
/// @since 0.0.0
int my_strlen(char const *str);
/// Get an int out of a string
/// @param str String from which we get the number
/// @returns The string as an int
/// @since 0.0.0
int my_atoi(char const *str);
/// Sort an array of int
/// @param tab pointer to the array to sort
/// @since 0.0.0
void my_sort_int_array(int *tab);
/// Sort an array of strings
/// @param tab pointer to the array to sort
/// @since 0.0.0
char **sort_string_array(char **array);
/// Get the square root of an int
/// @param nb Get the square root of this number
/// @returns The square root of nb
/// @since 0.0.0
int my_compute_square_root(int nb);
/// Check if a number is prime
/// @param nb Number to test
/// @returns 1 if nb is prime
/// @since 0.0.0
int my_is_prime(int nb);
/// Get the next number that is prime
/// @param nb Number to test
/// @returns Next prime number
/// @since 0.0.0
int my_find_prime_sup(int nb);
/// Copy a string into a other
/// @param dest Destination of the string
/// @param src String to copy
/// @returns The string copied
/// @since 0.0.0
char *my_strcpy(char *dest, char const *src);
/// Copy n characters of a string into a other
/// @param dest Destination of the string
/// @param src String to copy
/// @param n Number of characters to copy
/// @returns The string copied
/// @since 0.0.0
char *my_strncpy(char *dest, char const *src, int n);
/// Reverse a string
/// @param str String to reverse
/// @returns The string reversed
/// @since 0.0.0
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int *my_intdup(int nb);
int *my_intdup_ptr(int *nb);
int my_intcmp(int *nb1, int *nb2);
/// Check if two strings are identical
/// @param s1 First string
/// @param s2 Second string
/// @returns The ascii difference between the strings
/// @since 0.0.0
int my_strcmp(char const *s1, char const *s2);
/// Check if two strings are identical until n characters
/// @param s1 First string
/// @param s2 Second string
/// @param n Number of characters to check
/// @returns The ascii difference between the strings
/// @since 0.0.0
int my_strncmp(char const *s1, char const *s2, int n);
/// All lowcase characters of a string become uppcase
/// @param str String to transform
/// @returns The uppcase string
/// @since 0.0.0
char *my_strupcase(char *str);
/// All uppcase characters of a string become lowcase
/// @param str String to transform
/// @returns The lowcase string
/// @since 0.0.0
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcat_char(char *dest, char src);
char *my_strncat(char *dest, char const *src, int nb);
void my_exception(void);
void swap_numbers(int *int_1, int *int_2);
/// Turns a string into an array
/// @param str The string to put into an array
/// @param delim Delimitators that will cut the string
/// @returns The array that represents the string cut by the delimitators
/// @since 0.0.0
char **my_str_to_word_array(char *str, char *delims);
void print_arr(char **arr);
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
/// Simulates printf function
/// @param str Format of the string to print
/// @param var variables that will be printed
/// @since 0.0.0
void my_printf(char const *str, ...);
void my_putstr_nonprintable(char const *str);
/// Print an array of strings
/// @param tab The array that will be print
/// @param string_between The string that will be between strings of the array
/// @since 0.0.0
void my_put_tab(char **tab, char *string_between);
/// Calculate the power of a number
/// @param nb Nb to compute
/// @param p Power of the nb
/// @returns result of calculation
int my_compute_power_rec(int nb, int p);
/// Free an array of char **
/// @param array Array to free
/// @since 0.0.0
void my_free_array(char **array);
void my_free(void *ptr);
char *open_and_read_file(char *filepath);
void my_swap_int(int *a, int *b);
int my_factorial(int nb);

#endif