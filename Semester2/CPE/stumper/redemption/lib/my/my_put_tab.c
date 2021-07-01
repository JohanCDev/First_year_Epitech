/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_put_tab
*/

int my_putstr(char const *str);
void my_putchar(char c);

void my_put_tab(char **tab, char *string_between)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        if (tab[i + 1]) {
            my_putstr(string_between);
        } else
            my_putchar('\n');
        i++;
    }
}