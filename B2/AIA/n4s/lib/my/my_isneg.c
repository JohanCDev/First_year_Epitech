/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** desc
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    }
    if (n >= 0) {
        my_putchar('P');
    }
    return (0);
}
