/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** desc
*/

char *my_strcat(char *dest, char const *src)
{
    int length;
    int i;

    length = 0;
    i = 0;
    while (dest[length])
        length++;
    while (src[i]) {
        dest[length] = src[i];
        length++;
        i++;
    }
    dest[length] = 0;
    return (dest);
}
