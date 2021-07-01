/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** desc
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar(' ');
    }
}
