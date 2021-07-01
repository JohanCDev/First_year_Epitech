/*
** EPITECH PROJECT, 2018
** DO - OP
** File description:
** Simple operations
*/

#include "my.h"

int add(int nb1, int nb2);

int subs(int nb1, int nb2);

int multi(int nb1, int nb2);

int divi(int nb1, int nb2);

int modu(int nb1, int nb2);

int do_op(int nb1, char operator, int nb2)
{
    int res = 0;
    int (*fc[5])(int, int) = {&add, &subs, &multi, &divi, &modu};
    char operators[5] = {'+', '-', '*', '/', '%'};

    for (int i = 0; i < 5; i++) {
        if (operators[i] == operator) {
            res = fc[i](nb1, nb2);
            break;
        }
    }
    my_put_nbr(res);
    return (res);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (84);
    if (argv[2][0] == '%' && my_getnbr(argv[3]) == 0) {
        my_putstr("Stop: modulo by zero");
        return (84);
    }
    if (argv[2][0] == '/' && my_getnbr(argv[3]) == 0) {
        my_putstr("Stop: division by zero");
        return (84);
    }
    do_op(my_getnbr(argv[1]), argv[2][0], my_getnbr(argv[3]));
}