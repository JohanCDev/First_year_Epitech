/*
** EPITECH PROJECT, 2021
** palyndromes
** File description:
** my_factorial
*/

int my_factorial(int nb)
{
    if (nb < 0 || nb >= 13)
        return 0;
    if (nb == 0)
        return 1;
    else {
        return nb * my_factorial(nb - 1);
    }
}