/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** Displays alphabet in reverse
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (int letter = 26; letter > 0; letter--) {
        my_putchar(letter + 96);
    }
    return (0);
}
