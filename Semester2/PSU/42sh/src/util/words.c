/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Word related functions
*/

#include <libmy/ascii/character.h>

#include "util.h"

size_t sh_count_words(char const *str)
{
    size_t word_count = 0;

    if (str == NULL)
        return 0;
    do {
        while (my_isspace(*str))
            ++str;
        if (*str != '\0') {
            ++word_count;
            ++str;
        }
        while (*str != '\0' && !my_isspace(*str))
            ++str;
    } while (*str != '\0');
    return word_count;
}

sh_lstr_t sh_next_word(char const *str)
{
    sh_lstr_t word;

    if (str == NULL)
        return SH_LSTR(NULL, 0);
    while (my_isspace(*str))
        ++str;
    if (*str == '\0')
        return SH_LSTR(NULL, 0);
    word = SH_LSTR(str, 0);
    while (*str != '\0' && !my_isspace(*str))
        ++str;
    word.length = str - word.value;
    return word;
}
