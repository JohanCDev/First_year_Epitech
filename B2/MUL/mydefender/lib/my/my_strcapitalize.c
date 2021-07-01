/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** desc
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i;
    int to_capitalize;

    my_strlowcase(str);
    to_capitalize = 1;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            to_capitalize = 0;
        if (str[i] >= 'a' && str[i] <= 'z' && to_capitalize) {
            to_capitalize = 0;
            str[i] -= 32;
        }
        if (str[i] >= ' ' && str[i] <= '.')
            to_capitalize = 1;
        i++;
    }
    return (str);
}
