/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** find prime sup to nb
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
     while (my_is_prime (nb) != 1) {
        nb++;
     }
     return (nb);
}
