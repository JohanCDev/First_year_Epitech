/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** desc
*/

void my_putchar(char c);

void my_exception(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int n = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9)
        my_put_nbr (nb / 10);
    if (nb == -2147483648)
        my_exception();
    else {
        n = nb % 10;
        my_putchar(n + '0');
    }
    return (0);
}
