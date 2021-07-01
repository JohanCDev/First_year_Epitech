/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    
    while (s1[i] != 0 && s1[i] != 0 && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
