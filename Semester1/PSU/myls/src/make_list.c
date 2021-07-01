/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** make_list
*/

#include "my.h"

void switch_sum(int sum, linked_list_s *list)
{
    switch (sum) {
        case 2 :
        case 3 :
            sort_alpha(list, list, 1);
            break;
        case 4 :
        case 5 :
            sort_time(list, list, 0);
            break;
        case 6 :
        case 7 :
            sort_time(list, list, 1);
            break;
    }
}

int make_flags(char *filepath, ls_s param)
{
    int nb_total_blocks = 0;
    char *filepath_tmp = malloc(sizeof(char) * 256);
    linked_list_s *list = 0;
    int sum = (param.d + param.l + param.r + param.t);

    filepath_tmp = my_strcpy(filepath_tmp, filepath);
    list = do_ls(filepath_tmp, &nb_total_blocks);
    sort_alpha(list, list, 0);
    switch_sum(sum, list);
    if (param.l) {
        print_long_list(nb_total_blocks, list);
    } else
        print_short_list(list);
    return (0);
}