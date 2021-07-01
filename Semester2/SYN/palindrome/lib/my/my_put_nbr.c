/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Diplays the input number
*/

void my_putchar(char c);

void my_exception(void)
{
    my_putchar(2 + 48);
    my_putchar(1 + 48);
    my_putchar(4 + 48);
    my_putchar(7 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
    my_putchar(3 + 48);
    my_putchar(6 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
}

int my_put_nbr(int nb)
{
    int actual_number = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if (nb == -2147483648) {
        my_exception();
    } else {
        actual_number = nb % 10;
        my_putchar(actual_number + '0');
    }
    return (0);
}