/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** desc
*/

int my_putstr(char const *str);

void my_putchar(char c);

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
