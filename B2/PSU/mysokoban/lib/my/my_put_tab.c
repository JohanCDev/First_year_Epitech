/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_put_tab
*/

#include "my.h"

int print_all(char **tab, char *string_between, int i)
{
    if (tab[i][0] != '\t') {
        my_putstr(tab[i]);
        if (tab[i + 1]) {
            my_putstr(string_between);
        } else
            my_putchar('\n');
    }
    i++;
    return (i);
}

void my_put_tab(char **tab, char *string_between)
{
    int i = 0;

    while (tab[i]) {
        i = print_all(tab, string_between, i);
    }
}