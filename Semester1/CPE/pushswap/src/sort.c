/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-johan.chrillesen
** File description:
** sort
*/

#include "my.h"
#include "pushswap.h"

list print_movement(list lists, char *movement)
{
    if (lists.size_l_a > 1 && (movement[2] == 'a' || movement[1] == 'a')) {
        if (lists.print_space == 1) {
            my_printf(" %s", movement);
        } else {
            my_printf("%s", movement);
            lists.print_space = 1;
        }
    } else if (lists.size_l_b > 1 && (movement[2] == 'b' || \
    movement[1] == 'b')) {
        if (lists.print_space == 1) {
            my_printf(" %s", movement);
        } else {
            my_printf("%s", movement);
            lists.print_space = 1;
        }
    }
    return (lists);
}

list put_in_list_a(list lists)
{
    while (lists.size_l_b > 0) {
        lists = push_into_a(lists);
        lists = print_movement(lists, "pa");
    }
    return (lists);
}

list help_sort(list lists, int pos_smallest_nb)
{
    for (int i = lists.size_l_a - pos_smallest_nb; i != 0; i--) {
        lists = rotate_right_a(lists);
        lists = print_movement(lists, "rra");
    }
    return (lists);
}

list sort_list(list lists)
{
    int pos_smallest_nb = 0;
    int smallest_nb = lists.l_a[0];

    for (int i = 1; i < lists.size_l_a; i++) {
        if (lists.l_a[i] < smallest_nb) {
            pos_smallest_nb = i;
            smallest_nb = lists.l_a[i];
        }
    }
    if (lists.size_l_a / 2 > pos_smallest_nb) {
        for (int i = 0; i != pos_smallest_nb; i++) {
            lists = rotate_a(lists);
            lists = print_movement(lists, "ra");
        }
    } else {
        lists = help_sort(lists, pos_smallest_nb);
    }
    lists = push_into_b(lists);
    lists = print_movement(lists, "pb");
    return (lists);
}

void start_sort(list lists)
{
    for (int i = 0; lists.size_l_a > 0; i++)
        lists = sort_list(lists);
    lists = put_in_list_a(lists);
    my_putchar('\n');
}