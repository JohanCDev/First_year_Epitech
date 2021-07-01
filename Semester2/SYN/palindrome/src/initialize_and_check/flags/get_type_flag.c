/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** get_type_flag
*/

#include "my.h"
#include "pal.h"

int update_value_flag_str(char *flag, char *flag_to_find, int *flag_code, \
int value_to_insert);

int get_type_flag_str(flags_t *flags, char *flag, char *value_to_insert)
{
    if (update_value_flag_str(flag, NFLAG, &flags->n, \
        my_atoi(value_to_insert)) == -1 && \
        update_value_flag_str(flag, PFLAG, &flags->p, \
        my_atoi(value_to_insert)) == -1 && \
        update_value_flag_str(flag, BASEFLAG, &flags->base, \
        my_atoi(value_to_insert)) == -1 && \
        update_value_flag_str(flag, IMINFLAG, &flags->imin, \
        my_atoi(value_to_insert)) == -1 && \
        update_value_flag_str(flag, IMAXFLAG, &flags->imax, \
        my_atoi(value_to_insert)) == -1)
        return (my_put_error("A flag is unknown try with -h\n", -1));
    return 0;
}