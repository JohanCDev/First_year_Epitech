/*
** EPITECH PROJECT, 2020
** my_show_str
** File description:
** 
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void dec_to_hex(int nbr)
{
    int remainder;
    int i = 0;
    char str[10];

    if (nbr == 0) {
        str[0] = '0';
    }
    while (nbr != 0) {
        remainder = nbr % 16;
        if (remainder < 10) {
            str[i++] = 48 + remainder;
        } else {
            str[i++] = 55 + remainder + 32;
        }
        nbr = nbr / 16;
    }
    my_putchar('\\');
    if (nbr <= 15) {
        my_putchar('0');
    }
    for (int j = i; j >= 0; j--) {
        my_putchar(str[j]);
    }
}

int my_str_isprintable(char const *str)
{
    int is_okay = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else if (str[i] <= 31) {
            dec_to_hex(str[i]);
        }
    }
    return (is_okay);
}

int my_showstr(char const *str)
{
    my_str_isprintable(str);
    return (0);
}

int main(void)
{
    my_showstr("I love \n ponies");
    return (0);
}
