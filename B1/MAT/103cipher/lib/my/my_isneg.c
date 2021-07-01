/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Displays N or P
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return (0);
}
