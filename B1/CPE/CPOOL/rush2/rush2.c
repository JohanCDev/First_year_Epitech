/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** count letters
*/

#include "include/my.h"
#include <unistd.h>

void print_result(char *search, int nbr_letter, int nbr_letters_total)
{
    my_putstr(search);
    my_putchar(':');
    my_put_nbr(nbr_letter);
    my_putstr(" (");
    my_put_nbr((nbr_letter * 10000) / (nbr_letters_total * 100));
    my_putchar('.');
    if ((((nbr_letter * 10000) % (nbr_letters_total * 100)) / \
    nbr_letters_total) < 10)
    my_putchar('0');
    my_put_nbr(((nbr_letter * 10000) % (nbr_letters_total * 100)) / \
    nbr_letters_total);
    my_putstr("%)\n");
}

int check_alpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    return (1);
    else
    return (0);
}

float calculate_nbr_letters(char *str, char *search, int print)
{
    int i = 0;
    int nbr_letter = 0;
    int nbr_letters_total = 0;

    if (my_str_isupper(search) == 1)
    my_strupcase(str);
    else
    my_strlowcase(str);
    while (str[i] != 0) {
        if (search[0] == str[i])
        nbr_letter++;
        if (check_alpha(str[i]))
        nbr_letters_total++;
        i++;
    }
    if (print)
    print_result(search, nbr_letter, nbr_letters_total);

    return (((float)nbr_letter / nbr_letters_total * 100));
}

int get_biggest_score(int l1, int l2, int l3, int l4)
{
    if (l1 > l2 && l1 > l3 && l1 > l4)
    return (1);
    if (l2 > l1 && l2 > l3 && l2 > l4)
    return (2);
    if (l3 > l1 && l3 > l2 && l3 > l4)
    return (3);
    if (l4 > l1 && l4 > l2 && l4 > l3)
    return (4);
}

int main(int ac, char **av)
{
    int i = 0;
    if (av[1] == NULL)
    return (84);

    while (i < (ac - 2)) {
        calculate_nbr_letters(av[1], av[i + 2], 1);
        i++;
    }

    get_language_estimate(av[1]);

    return (0);
}
