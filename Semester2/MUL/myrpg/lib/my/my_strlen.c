/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** desc
*/

int my_strlen(char const *str)
{
    int length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return (length);
}
