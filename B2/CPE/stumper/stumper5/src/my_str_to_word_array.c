/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** my_str_to_word_array
*/

#include "hangman.h"

typedef struct word_arr_s {
    int i;
    int start;
} t_word_arr;

int my_get_char_in(char const *str, char c)
{
    for (int i = 0; i < (int)strlen(str); i++)
        if (str[i] == c)
            return 1;
    return 0;
}

static int count_words(char *str, char *delims)
{
    int words = 0;

    while (*str) {
        while (*str && my_get_char_in(delims, *str))
            str++;
        words += ((*str) != 0);
        while (*str && !my_get_char_in(delims, *str))
            str++;
    }
    return words;
}

t_word_arr get_len_word(char *str, char *delims, t_word_arr word_arr)
{
    while (str[word_arr.i] && my_get_char_in(delims, str[word_arr.i]))
        word_arr.i++;
    word_arr.start = word_arr.i;
    while (str[word_arr.i] && !my_get_char_in(delims, str[word_arr.i]))
        word_arr.i++;
    return (word_arr);
}

char **my_str_to_word_array(char *str, char *delims)
{
    int count = count_words(str, delims);
    char **array = malloc(sizeof(char *) * (count + 1));
    t_word_arr word_arr = {0, 0};
    int w = 0;

    if (array == NULL)
        return (NULL);
    while (str[word_arr.i]) {
        word_arr = get_len_word(str, delims, word_arr);
        array[w] = malloc(sizeof(char) * (word_arr.i - word_arr.start + 1));
        if (array[w] == NULL) {
            free_array(array);
            return (NULL);
        }
        strncpy(array[w], str + word_arr.start, (word_arr.i - word_arr.start));
        array[w++][word_arr.i - word_arr.start] = 0;
    }
    array[w] = NULL;
    return array;
}