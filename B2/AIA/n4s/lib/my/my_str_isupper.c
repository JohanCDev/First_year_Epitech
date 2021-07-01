/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** desc
*/

int my_str_isupper(char const *str)
{
    int i;

    i = 0;
    if (str == 0)
        return (1);
    while (str[i] >= 'A' && str[i] <= 'Z')
        i++;
    if (str[i] == 0)
        return (1);
    return (0);
}
