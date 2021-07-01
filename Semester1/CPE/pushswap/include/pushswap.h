/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-bspushswap-johan.chrillesen
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

typedef struct
{
    int *l_a;
    int size_l_a;
    int *l_b;
    int size_l_b;
    int ret;
    int print_space;
}list;
int *add_malloc(int *array, int size, int nb_box_more);
int *del_malloc(int *array, int size, int nb_box_less);
list push(list lists);
list pop(list lists);
list push_into_a(list lists);
list push_into_b(list lists);
list swap_a(list lists);
list swap_b(list lists);
list rotate_a(list lists);
list rotate_b(list lists);
list rotate_right_a(list lists);
list rotate_right_b(list lists);
void start_sort(list lists);
list sort_list(list lists);
list put_in_list_a(list lists);
list print_movement(list lists, char *movement);

#endif