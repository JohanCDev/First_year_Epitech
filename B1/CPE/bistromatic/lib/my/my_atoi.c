/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = ((res * 10) + (str[i] - 48));
        }
        i++;
    }
    if (str[0] == '-')
        res *= -1;
    return (res);
}