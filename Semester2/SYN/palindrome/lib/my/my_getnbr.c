/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** Display a number as a string
*/

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;
    int minus = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            minus = -minus;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    nb = minus * nb;
    return (nb);
}