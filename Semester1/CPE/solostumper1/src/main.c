/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-solostumper01-johan.chrillesen
** File description:
** main
*/

#include "my.h"

int swap_string(char *s1, char *s2, int **indexes, int i)
{
    char *stock = malloc(sizeof(char) * my_strlen(s1) + 1);
    char *ptr_stock = stock;
    int *tmp = indexes[i];
    int swapped = 1;

    if (my_strcmp(s1, s2) > 0)
    {
        ptr_stock = my_strcpy(stock, s1);
        my_strcpy(s1, s2);
        my_strcpy(s2, ptr_stock);
        indexes[i] = indexes[i + 1];
        indexes[i + 1] = tmp;
        swapped = 0;
    }
    free(stock);
    return (swapped);
}

void my_sort_str_array(char **array, int **indexes, int size)
{
    int done = 0;
    int count_done = 0;

    while (count_done != size - 1)
    {
        count_done = 0;
        for (int i = 0; i < size - 1; i++)
        {
            done = swap_string(array[i], array[i + 1], indexes, i);
            done == 1 ? count_done++ : count_done;
        }
    }
}

int **get_majs(char **tab, int size)
{
    int **indexes = malloc(sizeof(int *) * size + 1);

    if (indexes == NULL)
    {
        indexes[1][0] = 84;
        return (indexes);
    }
    for (int i = 0; i < size; i++)
    {
        indexes[i] = malloc(sizeof(int) * my_strlen(tab[i]));
        for (int j = 0; j < my_strlen(tab[i]); i++)
        {
            if (tab[i][j] >= 'A' && tab[i][j] <= 'Z')
                indexes[i][j] = 1;
            else
                indexes[i][j] = 0;
            indexes[i][j + 1] = 3;
        }
        indexes[i + 1][0] = 2;
    }
    return (indexes);
}

void put_majs(s_swapping *swap)
{
    for (int i = 0; i < swap->size; i++)
        for (int j = 0; j < my_strlen(swap->array[i]); j++)
            if (swap->majs_indexes[i][j] == 1)
                swap->array[i][j] -= 32;
}

int main(int argc, char **argv)
{
    s_swapping *swap = malloc(sizeof(s_swapping));

    if (argc != 2)
    {
        my_printf("\n");
        return (0);
    }
    swap->size = count_args(argv[1]);
    swap->array = my_str_to_word_array(argv[1]);
    swap->majs_indexes = NULL;
    swap->majs_indexes = get_majs(swap->array, swap->size);
    if (swap->majs_indexes[1][0] == 84)
        return (84);
    for (int i = 0; i < swap->size; i++)
        my_strlowcase(swap->array[i]);
    my_sort_str_array(swap->array, swap->majs_indexes, swap->size);
    put_majs(swap);
    return (0);
}