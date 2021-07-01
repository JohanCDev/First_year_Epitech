/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** 
*/

int my_str_isalpha(char const *str)
{
    int is_okay = 0;
    
    if (str[0] == 0)
        is_okay = 1;
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}
