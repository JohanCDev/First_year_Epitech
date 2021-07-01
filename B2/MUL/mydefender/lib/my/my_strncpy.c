/*
** EPITECH PROJECT, 2020
** my_strncopy
** File description:
** desc
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
