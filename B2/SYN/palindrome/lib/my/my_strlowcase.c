/*
** EPITECH PROJECT, 2020
** my_str_lowcase
** File description:
** desc
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('z' - 'Z');
    return (str);
}
