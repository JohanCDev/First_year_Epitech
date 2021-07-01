/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** desc
*/

int my_str_isupper(char const *str)
{
    int is_okay = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}

