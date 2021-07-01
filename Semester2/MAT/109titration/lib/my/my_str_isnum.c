/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** desc
*/

#include <stdbool.h>

int my_str_isnum(char const *str)
{
    int is_okay = 0;
    int i = 0;
    bool float_found = 0;

    for (; str[i] != 0; i++) {
        if ((str[i] >= 48 && str[i] <= 57))
            is_okay = 1;
        else if (str[i] == '.' && float_found == 0) {
            is_okay = 1;
            float_found = 1;
        } else
            return (0);
    }
    return (is_okay);
}