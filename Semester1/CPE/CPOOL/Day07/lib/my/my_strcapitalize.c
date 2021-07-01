/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** 
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int to_upcase;

    my_strlowcase(str);
    to_upcase = 1;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 48 && str[i] <= 57)
            to_upcase = 0;
        if (to_upcase && str[i] >= 97 && str[i] <= 122) {
            to_upcase = 0;
            str[i] -= 32;
        }
        if (str[i] >= 32 && str[i] <= 46)
            to_upcase = 1;
    }
    return (str);
}
