/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-101pong-tanguy.bellicha
** File description:
** my_str_isfloat
*/

int my_str_isfloat(char const *str)
{
    int is_okay = 0;
    int got_period = 0;

    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && i != 0)) {
            if (str[i] == '.' && got_period == 0) {
                got_period = 1;
            }
            is_okay = 1;
        }
        else
            return (0);
    }
    return (is_okay);
}