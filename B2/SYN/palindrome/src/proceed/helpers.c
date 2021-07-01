/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** helpers
*/

#include "pal.h"
#include "my.h"
#include <stdlib.h>

char *get_new_number(char *number)
{
    char *new_number = my_strdup(number);
    int new_nbr_as_int = 0;

    new_number = my_revstr(new_number);
    new_nbr_as_int = my_atoi(new_number);
    my_free(new_number);
    return my_itoa(my_atoi(number) + new_nbr_as_int);
}

void print_result(int nb_that_lead, char *nb_pal, int nb_it, int base)
{
    my_printf("%d leads to %s in %d iteration(s) in base %d\n", nb_that_lead, \
    nb_pal, nb_it, base);
}

bool is_palindrom(char *number)
{
    char *rev = my_strdup(number);

    rev = my_revstr(rev);
    if (!my_strcmp(number, rev)) {
        my_free(rev);
        return 1;
    }
    my_free(rev);
    return 0;
}