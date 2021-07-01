/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** check_different_words
*/

#include "my.h"
#include "antman.h"

int compress_string(s_antman *antman)
{
    int i = 0;

    while (i < my_strlen(antman->file_content)) {
        i = fill_list(antman, i);
        if (i == -1)
            return (84);
        antman->nb++;
    }
    antman->word_indexes[antman->nb] = -1;
    if (fill_differents_words(antman) == 84) {
        return (84);
    }
    i = 0;
    while (antman->list_of_words[i]) {
        if (find_in_list(antman, i) == -1)
            return (84);
        i++;
    }
    return (0);
}

int check_different_words(s_antman *antman, int i_main)
{
    if (!antman->list_of_words[i_main])
        return (-2);
    if (!word_is_in_list(antman->list_of_words[i_main], \
    antman->differents_words)) {
        antman->differents_words = add_in_list\
        (antman->list_of_words[i_main], antman->differents_words);
        if (antman->differents_words == NULL)
            return (-2);
    }
    return (i_main);
}

int check_end(s_antman *antman, int i, int k)
{
    if (!my_strcmp(antman->list_of_words[i], antman->differents_words[k])) {
        if (antman->word_indexes[i + 1] != -1)
            antman->word_indexes[i + 1] = k;
        return (1);
    }
    return (0);
}