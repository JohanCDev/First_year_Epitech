/*
** EPITECH PROJECT, 2020
** mu_put_nbr
** File description:
** test
*/
extern void my_putchar(char c);
extern int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(-235135);
    my_put_nbr(56432);
    my_put_nbr(2147483647);
    my_put_nbr(-2147483647);
    mu_put_nbr(0);
}
