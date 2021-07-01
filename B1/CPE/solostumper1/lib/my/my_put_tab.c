/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_put_tab
*/

#include "my.h"

void my_put_tab(void **tab, char *string_between)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        if (tab[i + 1]) {
            my_putstr(string_between);
        } else
            my_putchar('\n');
        i++;
    }
}