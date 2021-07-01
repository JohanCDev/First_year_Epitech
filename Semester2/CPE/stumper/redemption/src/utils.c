/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** utils
*/

#include "calendar.h"
#include <stdlib.h>
#include "my.h"

bool is_in_ascending_order(char *str1, char *str2)
{
    char *tmp_str1 = my_strlowcase(str1);
    char *tmp_str2 = my_strlowcase(str2);

    for (int i = 0; str1[i] && str2[i]; i++) {
        if (str1[i + 1] == '\0' || str1[i] < str2[i])
            return true;
        if (str2[i + 1] == '\0' || str1[i] > str2[i])
            return false;
    }
    free(tmp_str1);
    free(tmp_str2);
    return true;
}

int count_int_tab(int *i_tab)
{
    int count = 0;

    if (i_tab == NULL)
        return -1;
    for (; i_tab[count] != -1; count++);
    return count;
}

int nb_emps_in_meeting(meeting_t *meeting)
{
    int size = 0;

    while (meeting->emp_id[size] != -1)
        size++;
    return (size);
}

int *remove_id_from_array_emp_id(int *array_id, int id_to_remove)
{
    int *new_array = NULL;
    int *tmp_array = NULL;
    int j = 0;

    new_array = malloc(sizeof(int) * (count_int_tab(array_id)));
    for (int i = 0; array_id[i] != -1; i++) {
        if (array_id[i] != id_to_remove)
            new_array[j++] = array_id[i];
    }
    tmp_array = malloc(sizeof(int) * (j + 1));
    for (int i = 0; i < j; i++)
        tmp_array[i] = new_array[i];
    tmp_array[j] = -1;
    free(array_id);
    free(new_array);
    return tmp_array;
}

int *add_id_from_array_emp_id(int *array_id, int id_to_add)
{
    int *new_array = NULL;
    int i = 0;

    new_array = malloc(sizeof(int) * (count_int_tab(array_id) + 2));
    for (; array_id[i] != -1; i++) {
        if (array_id[i] == id_to_add) {
            free(new_array);
            return (array_id);
        }
        new_array[i] = array_id[i];
    }
    new_array[i] = id_to_add;
    new_array[i + 1] = -1;
    free(array_id);
    return new_array;
}