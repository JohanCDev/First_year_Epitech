/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Power with recursive func
*/

int my_pow(int nb, int p)
{
    int result = nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (p > 1) {
        result = nb * my_pow(nb, p - 1);
    }
    return (result);
}