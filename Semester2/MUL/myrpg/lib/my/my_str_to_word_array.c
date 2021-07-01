/*
** EPITECH PROJECT, 2021
** bsminishell
** File description:
** my_str_to_word_tab
*/

#include "my.h"

int count_args(char const *str)
{
    int nb_words = 0;

    while (*str) {
        if (*str != ' ' && \
        (*(str + 1) == '\0' || *(str + 1) == ' ')) {
            nb_words++;
        }
        str++;
    }
    return (nb_words);
}

int get_len_word(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != ' '; i++);
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    char const *tmp = my_strdup(str);
    int nbr_words = count_args(tmp);
    char **array = malloc(sizeof(char *) * (nbr_words + 2));
    int j = 0;
    int i = 0;

    for (i = 0; i < nbr_words; i++) {
        array[i] = malloc(sizeof(char) * (get_len_word(str) + 1));
        j = 0;
        while (*str != ' ' && *str) {
            array[i][j++] = *str;
            str++;
        }
        str++;
        array[i][j] = '\0';
    }
    array[i] = 0;
    return (array);
}