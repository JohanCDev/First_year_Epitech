/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** desc
*/

int my_str_isnum(char const *str)
{
    int is_okay = 0;
    int is_neg = 0;

    for (int i = 0; str[i] != 0; i++) {
        if(((str[i] >= '0' && str[i] <= '9') || str[i] == '-') && is_neg <= 1) {
            if (str[i] == '-')
                is_neg++;
            is_okay = 1;
        } else
            return (0);
    }
    return (is_okay);
}
