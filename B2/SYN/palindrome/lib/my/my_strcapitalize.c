/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** desc
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('z' - 'Z');
    return (str);
}