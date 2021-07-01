/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** calcul square root
*/
int my_compute_square_root(int nb)
{
    int i;

    if (nb < 0)
        return (0);
    for (i = 0; i * i != nb; i++) {
        if (i > nb)
            return (0);
    }
    return (i);
}
