/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** desc
*/

char *my_strstr(char *str, char const *to_find)
{
    int i;

    if (str[0] == '\0')
        return (0);
    for (i = 0; to_find[i] != '\0'; i++) {
        if (to_find[i] != str[i])
            return (my_strstr(str + 1, to_find));
    }
    return (str);
}
