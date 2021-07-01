/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** desc
*/

int my_str_isnum(char const *str)
{
    int i;
    int length;

    i = 0;
    length = 0;
    if (str == 0)
        return (1);
    while (str[length] != 0)
        length++;
    length--;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == 0)
        return (1);
    return (0);
}
