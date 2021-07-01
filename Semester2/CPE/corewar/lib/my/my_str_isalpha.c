/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** desc
*/

int my_str_isalpha(char const *str)
{
    int i;

    i = 0;
    if (str[0] == '\0')
        return (1);
    while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}
