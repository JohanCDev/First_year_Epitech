/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** my.h
*/
#include <stddef.h>

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
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
char *my_strdup(char *src);
int my_isnum(char a);
char *my_calloc(size_t nmemb, size_t size);
void *my_memset(char *s, int c, size_t n);
int my_put_nbr_base(int nbr, char *base);
int my_printf(char const *str, ...);
int my_put_unpritable(char const *str);
int my_putchar_unpritable(char c);
unsigned int my_int_to_unsigned(int nb);
int my_put_unsignedint(int i);
int my_put_ptr(unsigned long nb);
char *my_calloc_char(size_t nmemb, size_t size, char default_char);
char *my_memset_char(char *s, char c, size_t n);
char *load_file_in_mem(char const *filepath);
char **mem_alloc_2d_array_calloc(int nb_rows, int nb_cols);
char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols);
