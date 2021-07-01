/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** proceed
*/

#include "pal.h"
#include "my.h"
#include <stdlib.h>

int get_new_nb(int nb, char *nb_to_check, pal_t *pal)
{
    char *rev_nb_to_add = NULL;
    char *nb_as_char_in_base = NULL;

    rev_nb_to_add = my_revstr(nb_to_check);
    nb_as_char_in_base = change_base_to_dec(rev_nb_to_add, pal->flags.base);
    nb = my_atoi(nb_as_char_in_base) + nb;
    my_free(nb_as_char_in_base);
    return nb;
}

int proceed_increasing_number(pal_t *pal)
{
    char *nb_to_check = NULL;
    int num = pal->flags.n;
    int count = 0;
    char *num_as_str = NULL;

    do {
        nb_to_check = change_base_from_dec(num, pal->flags.base);
        if (is_palindrom(nb_to_check) && count >= pal->flags.imin) {
            num_as_str = my_itoa(num);
            print_result(pal->flags.n, num_as_str, count, pal->flags.base);
            my_free(nb_to_check);
            my_free(num_as_str);
            return 0;
        }
        num = get_new_nb(num, nb_to_check, pal);
        if (pal->flags.base != 10)
            my_free(nb_to_check);
    } while (++count <= pal->flags.imax);
    my_printf("no solution\n");
    return 0;
}

int do_a_single_line_of_p(pal_t *pal, char *nb_to_check, int i, \
bool answer_found)
{
    char *nb_tmp = change_base_to_dec(nb_to_check, pal->flags.base);
    int nb = my_atoi(nb_tmp);
    char *p_as_char = NULL;

    free_if_base_is_not_10(nb_tmp, pal->flags.base);
    for (int j = 0; j <= pal->flags.imax; j++) {
        nb_to_check = change_base_from_dec(nb, pal->flags.base);
        if (nb == pal->flags.p && j >= pal->flags.imin && \
        is_palindrom(nb_to_check)) {
            p_as_char = my_itoa(pal->flags.p);
            print_result(i, p_as_char, j, pal->flags.base);
            my_free(p_as_char);
            my_free(nb_to_check);
            return true;
        }
        nb = get_new_nb(nb, nb_to_check, pal);
        free_if_base_is_not_10(nb_to_check, pal->flags.base);
    }
    return answer_found;
}

int proceed_increasing_other(pal_t *pal)
{
    bool answer_found = false;
    char *nb_to_check = NULL;

    for (int i = 0; i <= pal->flags.p; i++) {
        nb_to_check = change_base_from_dec(i, pal->flags.base);
        if (nb_to_check == NULL)
            return -1;
        answer_found = do_a_single_line_of_p(pal, nb_to_check, i, answer_found);
        my_free(nb_to_check);
        nb_to_check = NULL;
    }
    if (answer_found == false)
        my_printf("no solution\n");
    return 0;
}

int proceed_code(pal_t *pal)
{
    if (pal->flags.n != -1) {
        return proceed_increasing_number(pal);
    } else if (pal->flags.p != -1) {
        return proceed_increasing_other(pal);
    }
    return 0;
}