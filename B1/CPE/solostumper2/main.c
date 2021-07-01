/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-solostumper02-johan.chrillesen
** File description:
** main
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int size = 0;
    while (*str != '\0') {
        str++;
        size++;
    }
    return (size);
}

char *my_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != 0) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return (str);
}

int my_str_isalpha(char const *str)
{
    int is_okay = 0;

    if (str[0] == 0)
        is_okay = 1;
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) \
        || (str[i] == ' '))
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}

void compare_strings(char *string1, char *string2)
{
    int value1 = 0;
    int value2 = 0;

    my_strlowcase(string1);
    my_strlowcase(string2);
    for (int i = 0; string1[i]; i++)
        value1 += string1[i];
    for (int i = 0; string2[i]; i++)
        value2 += string2[i];
    if (value1 == value2) {
        write(1, "anagram!\n", \
        my_strlen("anagram!\n"));
    }
    else {
        write(1, "no anagrams.\n", \
        my_strlen("no anagrams.\n"));
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        write(2, "Error : not enough arguments.\n", \
        my_strlen("Error : not enough arguments.\n"));
        return (84);
    }
    if (!my_str_isalpha(argv[1]))
        return (84);
    if (!my_str_isalpha(argv[2]))
        return (84);
    compare_strings(argv[1], argv[2]);
    return (0);
}