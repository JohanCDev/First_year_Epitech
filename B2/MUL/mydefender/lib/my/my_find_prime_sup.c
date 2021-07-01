/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** desc
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1)
        return (nb);
    else {
        while (my_is_prime(nb) != 1)
            nb++;
        return (nb);
    }
}
