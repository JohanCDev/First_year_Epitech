/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Display a number as a string
*/

int my_getnbr(char const *str)
{
    int i;
    int nb;
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
