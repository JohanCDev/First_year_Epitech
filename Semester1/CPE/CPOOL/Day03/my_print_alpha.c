/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Displays alphabet in order
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (int letter = 0; letter < 26; letter++) {
        my_putchar(letter + 97);
    }
    return (0);
}
