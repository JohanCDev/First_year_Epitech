/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** Displays 012 to 789
*/

void my_putchar(char c);

void print_spaces()
{
    my_putchar(',');
    my_putchar(' ');
}

void print_numbers(int nb_one, int nb_two, int nb_three)
{
    my_putchar(nb_one + 48);
    my_putchar(nb_two + 48);
    my_putchar(nb_three + 48);
}

int my_print_comb(void)
{
    int nb_one = 0;
    int nb_two = 0;
    int nb_three = 0;

    while (nb_one <= 7) {
        while (nb_two <= nb_one)
            nb_two++;
        while (nb_three <= nb_two)
            nb_three++;
        print_numbers(nb_one, nb_two, nb_three);
        if (nb_one != 7)
            print_spaces();
        if (nb_three == 9) {
            nb_two++;
            nb_three = 0;
        }
        if (nb_two == 9) {
            nb_one++;
            nb_two = 0;
        }
        nb_three++;
    }
    return (0);
}
