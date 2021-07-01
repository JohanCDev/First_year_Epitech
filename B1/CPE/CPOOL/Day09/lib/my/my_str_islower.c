/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** 
*/

int my_str_islower(char const *str)
{
    int is_okay = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}
