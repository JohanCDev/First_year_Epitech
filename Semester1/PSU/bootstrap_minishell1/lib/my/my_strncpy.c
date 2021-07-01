/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n characters to an other
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; n != 0; i++) {
        dest[i] = src[i];
        n--;
    }
    return (dest);
}
