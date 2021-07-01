/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** bistromatic
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

char *eval_expr(char const *base, char const *ops, \
char const *expr, unsigned int size);
char *my_infin_add(char *nb1, char *nb2);
char *my_infin_div(char *nb1, char *nb2);
char *my_infin_mod(char *nb1, char *nb2);
char *my_infin_sub(char *nb1, char *nb2);
int is_nb1_greater(char *nb1, char *nb2);
char *do_add(char *nb1, char *nb2, char *res);
char *do_sub(char *nb1, char *nb2, char *res);
char *clean_zeros(char *nbr_in_str);

#endif