/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** Displays digits in order
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int digit = 0; digit < 10; digit++) {
        my_putchar(digit + 48);
    }
    return (0);
}
