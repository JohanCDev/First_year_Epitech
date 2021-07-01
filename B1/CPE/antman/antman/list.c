/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** files
*/

#include "my.h"
#include "antman.h"

int fill_differents_words(s_antman *antman)
{
    int i_main = -1;

    antman->differents_words[0] = NULL;
    while (antman->list_of_words[++i_main]) {
        i_main = check_different_words(antman, i_main);
        if (i_main == -2)
            return (84);
    }
    return (0);
}

char **add_in_list(char *str, char **list)
{
    int i = 0;

    while (list[i])
        i++;
    list[i] = my_strdup(str);
    if (!my_strcmp(list[i], "Error"))
        return (NULL);
    list[++i] = 0;
    return (list);
}

int word_is_in_list(char *str, char **list)
{
    int i = 0;

    if (list[0] == NULL || str == NULL)
        return (0);
    for (; list[i]; i++) {
        my_printf("Comparing %s and %s\n", str, list[i]);
        if (!my_strcmp(str, list[i]))
            return (1);
    }
    return (0);
}

int find_in_list(s_antman *antman, int i)
{
    for (int k = 0; antman->differents_words[k]; k++) {
        if (check_end(antman, i, k))
            return (1);
    }
    return (1);
}

int fill_list(s_antman *antman, int start)
{
    int end = start;
    char *str = my_strdup(antman->file_content);

    if (!my_strcmp(str, "Error"))
        return (-1);
    while ((str[end] && char_is_alpha(str[end])) || \
    (is_special_char(str[end]) && end == start))
        end++;
    if ((antman->list_of_words[antman->i_list] = \
    malloc(sizeof(char *))) == NULL)
        return (-1);
    my_strncpy(antman->list_of_words[antman->i_list], \
    &antman->file_content[start], end - start);
    antman->list_of_words[antman->i_list][end - start + 1] = 0;
    antman->i_list++;
    while (str[end] && str[end] == ' ')
        end++;
    return (end);
}