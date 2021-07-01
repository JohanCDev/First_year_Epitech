/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** desc
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i++;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (0);
    return (s1[i] - s2[i]);
}
