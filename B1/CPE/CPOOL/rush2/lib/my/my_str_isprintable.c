/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** 
*/

int my_str_isprintable(char const *str)
{
    int is_okay = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}
