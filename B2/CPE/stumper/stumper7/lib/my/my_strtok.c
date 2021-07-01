/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** a function that splits a string into words
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

bool is_a_delimiter(char c, char *delimiters)
{
    for (int i = 0; delimiters[i]; i++)
        if (c == delimiters[i])
            return (true);
    return (false);
}

int how_many_word(char *str, char *delimiters)
{
    int nb = 0;
    int i = 0;

    while (str[i] && is_a_delimiter(str[i], delimiters))
        i++;
    while (str[i]) {
        while (str[i] && !is_a_delimiter(str[i], delimiters))
            i++;
        nb++;
        while (str[i] && is_a_delimiter(str[i], delimiters))
            i++;
    }
    return (nb);
}

char *catch_the_word(char *str, char *delimiters, int begin)
{
    int sz = 0;
    char *word;
    int j = 0;

    for (int i = begin; str[i] && !is_a_delimiter(str[i], delimiters); i++)
        sz++;
    word = malloc(sizeof(*word) * (sz +1));
    if (!word)
        return (NULL);
    for (int i = begin; str[i] && !is_a_delimiter(str[i], delimiters); i++) {
        word[j] = str[i];
        j++;
    }
    word[sz] = '\0';
    return (word);
}

/*
** Precise which delimiters you want or set it to 'NULL'
** By default, delimiters = ' \t\n'
*/
char **my_strtok(char *str, char *delimiters)
{
    char **tab;
    int nb;
    int j = 0;

    delimiters = (delimiters ? delimiters : " \t\n");
    nb = how_many_word(str, delimiters);
    tab = malloc(sizeof(*tab) * (nb + 1));
    if (!tab)
        return (NULL);
    tab[nb] = NULL;
    while (str[j] && is_a_delimiter(str[j], delimiters))
        j++;
    for (int i = 0; i < nb; i++) {
        tab[i] = catch_the_word(str, delimiters, j);
        while (str[j] && !is_a_delimiter(str[j], delimiters))
            j++;
        while (str[j] && is_a_delimiter(str[j], delimiters))
            j++;
    }
    return (tab);
}