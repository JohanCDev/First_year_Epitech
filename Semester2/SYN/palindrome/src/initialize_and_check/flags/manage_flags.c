/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** manage_flags
*/

#include "pal.h"
#include "my.h"

int update_value_flag_str(char *flag, char *flag_to_find, int *flag_code, \
int value_to_insert)
{
    if (!my_strcmp(flag, flag_to_find) && *flag_code == -1)
        *flag_code = value_to_insert;
    else
        return -1;
    return 0;
}

int check_all_flags(char *str, flags_t *flags, char *value_to_insert)
{
    if (((str[0] == '-' && !str[1]) || !value_to_insert) || \
        !my_str_isnum(value_to_insert))
        return (my_put_error\
        ("A flag is empty or a value isn't correct try with -h\n", -1));
    if (!my_strncmp(str, "-", 1))
        return (get_type_flag_str(flags, \
        &str[1], value_to_insert) == -1 ? -1 : 0);
    return (0);
}

void attribute_base_values(flags_t *flags)
{
    if (flags->base == -1)
        flags->base = 10;
    if (flags->imax == -1)
        flags->imax = 100;
    if (flags->imin == -1)
        flags->imin = 0;
}

int check_value_flags(flags_t *flags)
{
    char *p_in_base = NULL;

    if (flags->n == -1 && flags->p == -1)
        return my_put_error("You didn't put a mandatory argument\n", -1);
    attribute_base_values(flags);
    if (flags->base < 2 || flags->base > 10 || \
        (flags->n != -1 && flags->p != -1) || (flags->imin > flags->imax))
        return -1;
    if (flags->p != -1) {
        p_in_base = change_base_from_dec(flags->p, flags->base);
        if (is_palindrom(p_in_base) == 0) {
            my_free(p_in_base);
            return my_put_error("p is not a palindrom in the base given\n", -1);
        }
        my_free(p_in_base);
    }
    return 1;
}

int get_flags(flags_t *flags, char **argv)
{
    for (int i = 1; argv[i]; i += 2)
        if (check_all_flags(argv[i], flags, argv[i + 1]) == -1)
            return (-1);
    return (check_value_flags(flags));
}