/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** hexa
*/

#include "my.h"
#include "antman.h"

int print_result(s_antman *antman, int nb_searching, int i)
{
    int count = 0;

    while (my_getnbr(&antman->file_content[i]) == nb_searching) {
        count++;
        i = my_skipline(antman->file_content, i);
    }
    my_printf("%d|%X\n", count, nb_searching);
    count = 0;
    return (i);
}

int print_hexa_line(s_antman *antman)
{
    int i = 0;
    int nb_char = 0;
    int nb_searching = 0;
    char *str = antman->file_content;

    while (i < 3) {
        if (*str == '\n')
            i++;
        my_printf("%c", *str++);
        nb_char++;
    }
    i = nb_char;
    while (antman->file_content[i]) {
        nb_searching = my_getnbr(&antman->file_content[i]);
        i = print_result(antman, nb_searching, i);
    }
    return (0);
}