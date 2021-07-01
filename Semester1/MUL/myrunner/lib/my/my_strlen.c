/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** print nb char in string
*/

int my_strlen(char const *str)
{
    int size = 0;
    while (*str != '\0') {
        str++;
        size++;
    }
    return (size);
}
