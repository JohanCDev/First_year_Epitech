/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int i;
    int size = 0;
    char stock;

    while (str[size] != '\0') {
        size++;
    }
    size--;
    for (i = 0; i <= size; i++) {
        stock = str[i];
        str[i] = str[size];
        str[size] = stock;
        size--;
    }
    return (str);
}
