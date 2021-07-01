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
        if ((*str != ' ' && *str != '\n') && \
        (*(str + 1) == ' ' || *(str + 1) == '\0' || *(str + 1) == '\n')) {
            nb_words++;
        }
        str++;
    }
    return (nb_words);
}

int get_len_word(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != ' ' && str[i] != '\n'; i++);
    return (i);
}

char **replace_n_by_0(char **array, int nbr_words)
{
    for (int i = 0; i < nbr_words; i++) {
        for (int j = 0; array[i][j]; j++) {
            array[i][j] == '\n' ? array[i][j] = '\0' : 0;
        }
    }
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    char const *tmp = my_strdup(str);
    int nbr_words = count_args(tmp);
    char **array = malloc(sizeof(char *) * nbr_words + 1);
    int j = 0;
    int i = 0;

    for (i = 0; i < nbr_words; i++) {
        array[i] = malloc(sizeof(char) * get_len_word(str) + 1);
        j = 0;
        while ((*str != ' ' && *str != '\n') && *str) {
            array[i][j++] = *str;
            str++;
        }
        str++;
        array[i][j] = '\0';
    }
    array = replace_n_by_0(array, nbr_words);
    return (array);
}