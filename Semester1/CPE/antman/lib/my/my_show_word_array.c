/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** desc
*/

#include "my.h"

void my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        if (tab[i + 1])
            my_putchar(' ');
    }
    my_putchar('\n');
}
