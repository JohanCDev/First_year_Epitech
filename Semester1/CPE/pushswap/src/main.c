/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include "pushswap.h"

int check_specifications(list lists, int argc)
{
    if (argc == 2) {
        my_putchar('\n');
        return (0);
    }
    for (int i = 1; lists.l_a[i - 1] < lists.l_a[i]; i++) {
        if (i + 1 == lists.size_l_a) {
            my_putchar('\n');
            lists.ret = 1;
            return (0);
        }
    }
    return (1);
}

list get_args(int argc, char **argv, list lists)
{
    for (int i = 0; i < argc - 1; i++) {
        if (my_str_isnum(argv[i + 1]))
            lists.l_a[i] = my_getnbr(argv[i + 1]);
        else {
            my_put_error("Bad argument\n");
            lists.ret = 84;
            i = argc - 1;
        }
    }
    lists.size_l_a = argc - 1;
    lists.size_l_b = 0;
    return (lists);
}

int main(int argc, char **argv)
{
    list lists;

    lists.l_a = malloc(sizeof(int) * (argc - 1));
    lists.l_b = malloc(sizeof(int) * (argc - 1));
    lists.ret = 0;
    lists.print_space = 0;
    if (argc != 1) {
        lists = get_args(argc, argv, lists);
        if (lists.ret == 84)
            return (84);
    } else {
        my_put_error("Error, Usage : ./pushswap *list to sort*\n");
        return (84);
    }
    if (check_specifications(lists, argc) == 0)
        return (0);
    start_sort(lists);
    return (0);
}