/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print a string
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
}
