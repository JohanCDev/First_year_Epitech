/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** get_token
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#define is_neg(x) (x == '-')

#define is_num(x) (x >= '0' && x <= '9')

#define is_oper(x) (x == '-' || x == '+' || x == '*' || \
                    x == '/' || x == '%' || x == '(' || x == ')')

#define END   -1
#define NUMBER 0
#define SUM    1
#define FACT   2
#define L_PAR  3
#define R_PAR  4

void copy_num(char **str, pf_struct *pf_s)
{
    char *p;

    p = pf_s -> num;
    pf_s -> type = NUMBER;
    if (is_neg(**str)) {
        *p++ = '-';
        *str = *str + 1;
    }
    while (is_num(**str)) {
        *p++ = **str;
        *str = *str + 1;
    }
    *p = '\0';
}

void copy_oper(char **str, pf_struct *pf_s)
{
    switch (**str)
    {
        case '+' :
        case '-' :
            pf_s -> type = SUM;
            break;
        case '*' :
        case '/' :
        case '%' :
            pf_s -> type = FACT;
            break;
        case '(' :
            pf_s -> type = L_PAR;
            break;
        case ')' :
            pf_s -> type = R_PAR;
            break;
    }
    pf_s -> operator = **str;
    *str = *str + 1;
}

void get_token(char **str, pf_struct *elem)
{
    char *look_ahead = 0;

    if (!**str)
        return;
    look_ahead = *str+1;
    if (is_num(**str)) {
        copy_num(str, elem);
        return;
    }
    if (is_oper(**str)) {
        copy_oper(str, elem);
        return;
    }
    exit(84);
}