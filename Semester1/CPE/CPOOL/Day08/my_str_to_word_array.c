/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** 
*/

#include<stdlib.h>
#include "my.h"

int check_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else 
        return (0);
}

void print_arr(char **arr)
{
    for (int i = 0; arr[i] != 0; i++) {
        my_putstr(arr[i]);
        if (arr[i + 1] != 0 && (check_alphanum(*arr[i]) == 1))
            my_putchar(' ');
    }
}

int word_len(char const *str)
{
    int i = 0;
    
    while(*str++) {
        if (check_alphanum(*str) == 0)
            return (i);
        i++;
    }
    return (0);
}

int count_words(const char *tmp)
{
    int nbr_words = 0;
    int have_alphanum = 0;

    while (*tmp++) {
        if (check_alphanum(*tmp) == 0 && have_alphanum > 0) {
            ++nbr_words;
            have_alphanum = 0;
        }
        ++have_alphanum;
    }
    return (nbr_words);
}

char **my_str_to_word_array(char const *str)
{
    char const *tmp = str;
    int nbr_words = 0;
    int i;
    int j;
    char **arr;

    nbr_words = count_words(tmp);
    arr = malloc(sizeof(char *) * nbr_words + 1);
    for (i = 0; i < nbr_words; i++) {
        while (!(*str != '\0' && check_alphanum(*str)))
            ++str;
        arr[i] = malloc(sizeof(char) * word_len(str + 1));
        j = 0;
        while (*str != '\0' && (check_alphanum(*str) == 1)) {
            arr[i][j++] = *str;
            str++;
        }
        str++;
        arr[i][j] = '\0';
    }
    arr[i] = 0;
    return (arr);
}