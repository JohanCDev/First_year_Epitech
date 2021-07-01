/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** hexa_to_dec
*/

#include "my.h"
#include "giantman.h"

int hexa_to_dec(char *str)
{
    int final_nb = 0;
    int value = 0;
    int length = my_strlen(str) - 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            value = str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'F')
            value = str[i] - 65 + 10;
        final_nb += value * my_compute_power_rec(16, length);
        length--;
    }
    return (final_nb);
}

int print_result(s_giantman *giantman, int i)
{
    char *nbr = NULL;
    int value = 0;
    int count = 0;

    if (!(nbr = malloc(sizeof(char) * 5)))
        return (84);
    while (giantman->file_content[i]) {
        nbr = my_getstr(&giantman->file_content[i]);
        if (!my_strcmp(nbr, "Error"))
            return (84);
        count = my_getnbr(nbr);
        value = hexa_to_dec(&nbr[2]);
        for (int j = 0; j < count; j++)
            my_printf("%d\n", value);
        i = my_skipline(giantman->file_content, i);
    }
    return (0);
}

int print_dec_line(s_giantman *giantman)
{
    int i = 0;
    int nb_char = 0;
    char *str = giantman->file_content;

    while (i < 3) {
        if (*str == '\n')
            i++;
        my_printf("%c", *str++);
        nb_char++;
    }
    i = nb_char;
    if (print_result(giantman, i) == 84)
        return (84);
    return (0);
}