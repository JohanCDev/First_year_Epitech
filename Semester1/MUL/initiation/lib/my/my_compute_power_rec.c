/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Power with recursive func
*/

int my_compute_power_rec(int nb, int p)
{
    int result = result;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (result == 0) {
        result++;
    }
    if (p > 1) {
        result = nb * my_compute_power_rec(nb, p - 1);
        return (result);
    }
    return (0);
}
