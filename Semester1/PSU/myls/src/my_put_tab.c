/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** my_put_tab
*/

#include "my.h"

char **put_maj(char **tab, int *list_maj)
{
    for (int i = 0; tab[i]; i++)
        if (list_maj[i] == 1)
            tab[i][0] -= 32;
    return (tab);
}

int *make_list_maj(char **tab)
{
    int i = 0;
    int *list_index_maj = malloc(sizeof(int *) * 256);

    while (tab[i]) {
        if (is_upper(tab[i][0])) {
            list_index_maj[i] = 1;
        } else if (!is_upper(tab[i][0]))
            list_index_maj[i] = 0;
        i++;
    }
    list_index_maj[i] = -1;
    return (list_index_maj);
}

char **sort_tab_alpha(char **tab, int *list_maj)
{
    int i = 0;
    int j = 0;
    int nb = 0;
    char *tmp = malloc(sizeof(char) * 256);

    while (tab[nb])
        nb++;
    for (i = 0;  i < nb; i++) {
        for (j = i + 1; j < nb; j++) {
            if (my_strcmp(my_strlowcase(tab[i]), my_strlowcase(tab[j])) > 0) {
                my_swap_str(&tab[i], &tab[j]);
                my_swap_int(&list_maj[i], &list_maj[j]);
            }
        }
    }
    free(tmp);
    return (tab);
}

void my_put_tab(char **tab, char *string_between)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        if (tab[i + 1]) {
            my_putstr(string_between);
        } else
            my_putchar('\n');
        i++;
    }
}

void my_put_list(s_list *array)
{
    my_printf("%s ", array[0].rights);
    my_printf("%d ", array->nlinks);
    my_printf("%s ", array->file_master);
    my_printf("%s ", array->folder_master);
    my_printf("%d ", array->size);
    my_printf("%s ", array->time);
    my_printf("%s\n", array->name_file);
}