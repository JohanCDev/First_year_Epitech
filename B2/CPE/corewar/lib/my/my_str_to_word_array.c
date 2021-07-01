/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-bscorewar-johan.chrillesen
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_get_char_in(char const *str, char c)
{
    for (int i = 0; i < (int)my_strlen(str); i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int count_words_for_array(char *str, char *delims)
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

void free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i] != NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    if (array != NULL) {
        free(array);
        array = NULL;
    }
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
    int count = count_words_for_array(str, delims);
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
        my_strncpy(array[w], str + word_arr.start, \
        (word_arr.i - word_arr.start));
        array[w++][word_arr.i - word_arr.start] = 0;
    }
    array[w] = NULL;
    return array;
}
