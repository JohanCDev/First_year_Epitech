/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** raise to the power with iterative
*/
int my_compute_power_it(int nb, int p)
{
    int result = 1;

    if (p < 0)
        return (0);
    while (p != 0) {
        result = result * nb;
        p--;
    }
    return (result);
}
