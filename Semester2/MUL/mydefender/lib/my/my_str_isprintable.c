/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** desc
*/

int my_str_isprintable(char const *str)
{
    int i;

    i = 0;
    if (str == 0)
        return (1);
    while (str[i] >= ' ' && str[i] <= '~')
        i++;
    if (str[i] == 0)
        return (1);
    return (0);
}
