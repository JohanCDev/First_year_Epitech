/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort int in array
*/
void swap_numbers(int *int_1, int *int_2)
{
    if (*int_1 > *int_2) {
        int stock = *int_1;

        *int_1 = *int_2;
        *int_2 = stock;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;
    
    for (i = 0; i < size; i++) {
        for(j = 0; j < size - i - 1; j++) {
            swap_numbers(&array[j], &array[j + 1]);
        }
    }
}
