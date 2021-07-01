/*
** EPITECH PROJECT, 2020
** my_str_lowcase
** File description:
** 
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != 0) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return (str);
}
