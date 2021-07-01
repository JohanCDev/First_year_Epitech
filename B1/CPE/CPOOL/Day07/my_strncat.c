/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** copy n char to a string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = 0;
    int i = 0;

    while (dest[size])
        size++;
    while (src[i] && i < nb) {
        dest[size] = src[i];
        size++;
        i++;
    }
    dest[size] = 0;
    return (dest);
}
