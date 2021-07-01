/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints the contents of a null-terminated string array
*/

#include "libmy/io.h"

MY_IO_API int my_show_word_array(char *const *tab)
{
    if (!tab)
        return -1;
    while (*tab) {
        my_putstr(*tab++);
        my_putchar('\n');
    }
    return 0;
}
