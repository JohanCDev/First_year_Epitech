/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap the content of two int
*/

void my_swap_str(char **a, char **b)
{
    char *stock = *a;

    *a = *b;
    *b = stock;
}

void my_swap_int(int *a, int *b)
{
    int stock = *a;

    *a = *b;
    *b = stock;
}