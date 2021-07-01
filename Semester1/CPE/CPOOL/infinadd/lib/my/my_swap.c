/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap the content of two int
*/

void my_swap(int *a, int *b)
{
    int stock = *a;

    *a = *b;
    *b = stock;
}
