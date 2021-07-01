/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** my_itoa
*/

#include <stdlib.h>

int my_int_len(int nb)
{
    int div = 0;
    int count = 0;

    div = 1;
    count = 1;
    while (nb / div >= 1) {
        div = div * 10;
        count = count + 1;
    }
    return (count);
}

char *my_itoa(int nb)
{
    int div = 0;
    char *str = NULL;
    int i = 0;

    i = my_int_len(nb);
    if ((str = malloc(sizeof(char) * i)) == NULL)
        return (NULL);
    i = i - 1;
    div = 10;
    str[i] = '\0';
    while (i > 0) {
        str[i - 1] = (nb % div) + 48;
        nb = nb / 10;
        i = i - 1;
    }
    return (str);
}