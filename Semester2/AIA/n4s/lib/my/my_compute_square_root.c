/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** desc
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (result = 0; result * result != nb; result++) {
        if (result > nb)
            return (0);
    }
    return (result);
}
