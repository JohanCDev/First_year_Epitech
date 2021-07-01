/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** eval_expr2
*/

#include "include/my.h"
#include "include/bistromatic.h"
#include <stdlib.h>

#define is_num(x) (x >= '0' && x <= '9')? 1 : 0

#define is_sum(s) (s == '+' || s == '-')? 1 : 0

#define is_fact(f) (f == '*' || f == '/' || f == '%')? 1 : 0

#define c_to_i(c) (c - '0')

#define i_to_c(i) (i + '0')

#define END   -1
#define NUMBER 0
#define SUM    1
#define FACT   2
#define L_PAR  3
#define R_PAR  4

char *calcul_result(pf_struct *postfix)
{
    int ir = -1;
    char *a = 0;
    char *b = 0;
    char **res = (char **)malloc(sizeof(char *) * 128);

    while (postfix -> type != END) {
        if (postfix -> type == SUM || postfix -> type == FACT) {
            switch (postfix -> operator) {
                case '+':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = my_infin_add(a, b);
                    break;
                case '-':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = my_infin_sub(b, a);
                    break;
                case '*':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = my_infin_mult(a, b);
                    break;
                case '/':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = my_infin_div(b, a);
                    break;
                case '%':
                    a = res[ir--];
                    b = res[ir--];
                    res[++ir] = my_infin_mod(b, a);
                    break;
            }
        } else
            res[++ir] = postfix -> num;
        ++postfix;
    }
    return (res[ir]);
}

void copy_helper(pf_struct *to, pf_struct *from)
{
    to -> num = my_strdup(from -> num);
    to -> type = from -> type;
    to -> operator = from -> operator;
}

int oper_type(char oper) {
    switch(oper) {
        case '-' :
        case '+' :
            return (SUM);
            break;
        case '%' :
        case '*' :
        case '/' :
            return (FACT);
            break;
        default :
            return (-1);
    }
}

pf_struct *infix_to_postfix(char *ptr_s)
{
    int ip = -1;
    int io = -1;
    pf_struct *post = malloc(sizeof(pf_struct) * 128);
    char *oper = malloc(sizeof(char *) * 128);
    pf_struct helper;
    helper.num = (char *)malloc(sizeof(char)*128);

    while (*ptr_s) {
        get_token(&ptr_s, &helper);
        if (helper.type == NUMBER) {
            copy_helper(&post[++ip], &helper);
        }
        if (helper.type == SUM) {
            while (io > -1 && (is_sum(oper[io]) || is_fact(oper[io]))) {
                post[++ip].operator = oper[io--];
                post[ip].type = SUM;
            }
            oper[++io] = helper.operator;
        }
        if (helper.type == FACT) {
            while (io > -1 && is_fact(oper[io])) {
                post[++ip].operator = oper[io--];
                post[ip].type = FACT;
            }
            oper[++io] = helper.operator;
        }
        if (helper.type == L_PAR)
            oper[++io] = helper.operator;
        if (helper.type == R_PAR)
        {
            while (io > -1 && oper[io] != '(') {
                post[++ip].operator = oper[io];
                post[ip].type = oper_type(oper[io--]);
            }
            io--;
        }
    }
    while (io > -1) {
        post[++ip].operator = oper[io];
        post[ip].type = oper_type(oper[io--]);
    }
    post[++ip].type = END;
    return (post);
}

char *eval_expr(char const *base, char const *ops, \
char const *str, unsigned int size)
{
    char *p = (char *)malloc(sizeof(char) * my_strlen(str));
    char *str_result = (char *)malloc(sizeof(char) * 128);

    base = "0123456789";
    ops = "()+-*/%";
    my_strcpy(p, str);
    str_result = calcul_result(infix_to_postfix(p));
    return (str_result);
}