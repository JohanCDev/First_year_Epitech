/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** desc
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int is_neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            is_neg *= (-1);
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    nb *= is_neg;
    return (nb);
}

float my_getfloat(char const *str)
{
    int sign = 1;
    float coef = 10.0;
    float nbr = (float) my_getnbr(str);

    if (nbr < 0) {
        nbr *= -1;
        sign = -1;
    }
    while (*str == ' ' || *str == '+' || *str == '-' || \
        (*str >= '0' && *str <= '9'))
        str++;
    if (*str == '.') {
        while (str[1] >= '0' && str[1] <= '9') {
            nbr += (str[1] - '0') / coef;
            coef *= 10;
            str++;
        }
    }
    return (nbr * sign);
}