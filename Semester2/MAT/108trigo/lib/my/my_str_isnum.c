/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** desc
*/

int my_str_isnum(char const *str, int neg)
{
    int is_okay = 0;
    int i = 0;

    if (neg == 1)
        if (str[i] == '-')
            i += 1;
    for (; str[i] != 0; i++) {
        if ((str[i] >= 48 && str[i] <= 57))
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}
