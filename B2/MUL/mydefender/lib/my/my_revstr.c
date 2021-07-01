/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** desc
*/

char *my_revstr(char *str)
{
    char tempo;
    int cur_letter = 0;
    int length = 0;

    while (str[length] != '\0')
        length++;
    length--;
    while (cur_letter <= length) {
        tempo = str[cur_letter];
        str[cur_letter] = str[length];
        str[length] = tempo;
        cur_letter = cur_letter + 1;
        length = length - 1;
    }
    return (str);
}
