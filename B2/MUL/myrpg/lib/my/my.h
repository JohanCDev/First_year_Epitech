/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>

int my_strlen(char const *str);
float my_getfloat(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
char *my_itoa(int nb);

#endif /* !MY_H_ */