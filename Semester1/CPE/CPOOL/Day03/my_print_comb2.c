/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** Displays 00 01 to 98 99
*/

void my_putchar(char c);

int my_print_comb2(void)
{
    int nb_one = 0;
    int nb_two = 0;
    int nb_three = 0;
    int nb_four = 1;

    calcul_nb(nb_one, nb_two, nb_three, nb_four);
    return (0);
}

int calcul_nb(int nb_one, int nb_two, int nb_three, int nb_four)
{
    while (nb_one <= 9 && nb_two <= 9 && nb_three <= 9 && nb_four <=9) {
        my_putchar(nb_one + 48);
        my_putchar(nb_two + 48);
        my_putchar(' ');
        my_putchar(nb_three + 48);
        my_putchar(nb_four + 48);
        if (nb_one == 9 && nb_two == 8 && nb_three == 9 && nb_four == 9) {
        } else {
            my_putchar(',');
            my_putchar(' ');
        }
        if (nb_two >= 9 && nb_three >= 9 && nb_four >= 9) {
            nb_one++;
            nb_two = -1;
        }
        if (nb_three >= 9 && nb_four >= 9) {
            nb_two++;
            nb_three = nb_one;
            nb_four = nb_two;
        }
        if (nb_four >= 9) {
            nb_three++;
            nb_four = 0;
        } else {
            nb_four ++;
        }
    }
    return (0);
}
