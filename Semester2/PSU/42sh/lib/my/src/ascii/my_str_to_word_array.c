/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Splits a string into words
*/

#include <stdlib.h>
#include "libmy/ascii.h"

static int next_word(char const **begin, char const **end)
{
    while (**begin && my_isspace(**begin))
        ++(*begin);
    *end = *begin;
    if (!**begin)
        return 0;
    while (**end && !my_isspace(**end))
        ++(*end);
    return 1;
}

static int count_words(char const *str)
{
    int count = 0;
    char const *word_end;

    if (!str)
        return 0;
    while (next_word(&str, &word_end)) {
        str = word_end;
        ++count;
    }
    return count;
}

static int copy_word(char *words[], char const **str, int i)
{
    char *word;
    char const *word_end;
    int word_len;

    next_word(str, &word_end);
    word_len = (int)(word_end - *str);
    word = malloc(sizeof(*word) * (word_len + 1));
    if (!word) {
        my_free_str_array(words, i);
        return -1;
    }
    my_strncpy(word, *str, word_len);
    word[word_len] = 0;
    words[i] = word;
    *str = word_end;
    return 0;
}

MY_ASCII_API char **my_str_to_word_array(char const *str)
{
    int count = count_words(str);
    char **words = malloc(sizeof(*words) * (count + 1));

    if (!str || !words)
        return NULL;
    for (int i = 0; i < count; ++i)
        if (copy_word(words, &str, i) == -1)
            return NULL;
    words[count] = NULL;
    return words;
}
