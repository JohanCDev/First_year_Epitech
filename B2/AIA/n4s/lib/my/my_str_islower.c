/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** desc
*/

int my_str_islower(char const *str)
{
    int i;

    i = 0;
    if (str == 0)
        return (1);
    while (str[i] >= 'a' && str[i] <= 'z')
        i++;
    if (str[i] == 0)
        return (1);
    return (0);
}
