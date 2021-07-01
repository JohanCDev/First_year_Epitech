/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** desc
*/

char *my_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
