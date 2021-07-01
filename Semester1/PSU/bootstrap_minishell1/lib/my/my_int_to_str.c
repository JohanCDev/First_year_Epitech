/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** my_int_to_str
*/

#include "my.h"

char *int_to_str(int i)
{
    char *res = malloc(sizeof(char) * sizeof(i));

    if (i == 0) {
        return ("0");
    }
    while (i > 0) {
        my_strcat_char(res, (i % 10) + '0');
        i = (i - (i % 10))/10;
    }
    my_revstr(res);
    res[my_strlen(res)] = 0;
    return (res);
}