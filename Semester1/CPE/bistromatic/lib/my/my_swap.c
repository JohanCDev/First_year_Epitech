/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap the content of two int
*/

#include "my.h"

void my_swap(char *a, char *b)
{
    char *stock = my_strcpy(stock, a);

    a = my_strcpy(a, b);
    b = my_strcpy(b, stock);
}
