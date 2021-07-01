/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
