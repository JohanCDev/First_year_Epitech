/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "str_to_word_array.h"

char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);
void my_free_array(char **array);

int my_get_char_in(char const *str, char c)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == c)
            return 1;
    return 0;
}

static int count_words_array(char *str, char *delims)
{
    int words = 0;

    if (str == NULL || delims == NULL)
        return 0;
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
    int count = count_words_array(str, delims);
    char **array = malloc(sizeof(char *) * (count + 1));
    t_word_arr w_arr = {0, 0};
    int w = 0;

    if (array == NULL || str == NULL || delims == NULL)
        return (NULL);
    while (str[w_arr.i]) {
        w_arr = get_len_word(str, delims, w_arr);
        array[w] = malloc(sizeof(char) * (w_arr.i - w_arr.start + 1));
        if (array[w] == NULL) {
            my_free_array(array);
            return (NULL);
        }
        my_strncpy(array[w], str + w_arr.start, (w_arr.i - w_arr.start));
        array[w++][w_arr.i - w_arr.start] = 0;
    }
    array[w] = NULL;
    return array;
}