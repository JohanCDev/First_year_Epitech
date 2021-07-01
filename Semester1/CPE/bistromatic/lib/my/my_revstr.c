/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int size = 0;
    char stock = 0;

    while (str[size] != '\0') {
        size++;
    }
    size--;
    for (i = 0; i  <= size; i++) {
        stock = str[i];
        str[i] = str[size];
        str[size] = stock;
        size--;
    }
    return (str);
}
