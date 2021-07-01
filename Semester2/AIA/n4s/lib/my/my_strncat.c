/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** desc
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int length;
    int i;

    length = 0;
    i = 0;
    while (dest[length])
        length++;
    while (src[i] && i < nb) {
        dest[length] = src[i];
        length++;
        i++;
    }
    dest[length] = 0;
    return (dest);
}
