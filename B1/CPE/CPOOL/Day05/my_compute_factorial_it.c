/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** factorial with iteratives
*/
int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12) {
        return (0);
    } else if (nb == 0) {
        return (1);
    } else {
        while (nb != 1) {
            result = result * nb;
            nb--;
        }
        return (result);
    }
}
