/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-johan.chrillesen
** File description:
** rush3
*/

#include "my.h"

void verify_for_one(char *buff)
{
    if (buff[0] == 'o')
        my_putstr("[rush1-1] 1 1\n");
    else if (buff[0] == '*')
        my_putstr("[rush1-2] 1 1\n");
    else if (buff[0] == 'B')
        my_putstr("[rush1-3] || [rush1-4] || [rush1-5] 1 1\n");
    else
        my_putstr("none\n");
}

void print_length(int horizontal_i, int vertical_i)
{
    my_put_nbr(horizontal_i);
    my_putchar(' ');
    my_put_nbr(vertical_i);
    my_putchar('\n');
}

void verify_for_mult(char *buff, int horizontal_i, int vertical_i)
{
    if (buff[0] == 'o' && buff[horizontal_i - 1] == 'o')
        my_putstr("[rush1-1] ");
    if (buff[0] == '/' && buff[horizontal_i - 1] == '\\')
        my_putstr("[rush1-2] ");
    if (buff[0] == 'A' && buff[horizontal_i - 1] == 'A')
        my_putstr("[rush1-3] ");
    if (buff[vertical_i - horizontal_i - 1] == 'A' \
    && buff[horizontal_i - 1] == 'C')
        my_putstr("[rush1-4] ");
    if (buff[horizontal_i - 1] == 'C' \
    && buff[vertical_i - horizontal_i - 1] == 'C')
        my_putstr("[rush1-5] ");
    if ((buff[0] && buff[horizontal_i - 1]) != \
    ('o' || 'A' || '/' || 'B' || '*'))
        my_putstr("none");
}

int rush3(char *buff)
{
    int vertical_i = 0;
    int horizontal_i = 0;
    int i = 0;

    while (buff[horizontal_i] != '\n')
        horizontal_i++;
    if (horizontal_i == 1)
        verify_for_one(buff);
    if (horizontal_i != 1) {
        while (buff[i] != '\0') {
            if (buff[i] == '\n')
                vertical_i++;
            i++;
            }
        verify_for_mult(buff, horizontal_i, i);
        print_length(horizontal_i, vertical_i);
    }
    return (0);
}