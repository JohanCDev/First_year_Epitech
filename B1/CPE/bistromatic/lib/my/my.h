/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef MY_H_
#define MY_H_

typedef struct posfix_struct {
    int type;
    char *num;
    char operator;
} pf_struct;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(char *a, char *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
void my_exception(void);
void swap_numbers(int *int_1, int *int_2);
int check_alphanum(char c);
char **my_str_to_word_array(char const *str);
int count_words(const char *tmp);
int word_len(char const *str);
void print_arr(char **arr);
int do_op(int nb1, char operator, int nb2);
int add(int nb1, int nb2);
int subs(int nb1, int nb2);
int multi(int nb1, int nb2);
int divi(int nb1, int nb2);
int modu(int nb1, int nb2);
int my_atoi(char *str);
int my_error_atoi(char *str);
char *eval_expr(char const *base, char const *ops, \
char const *str, unsigned int size);
char *do_add(char *nb1, char *nb2, char *res);
char *my_infin_add(char *nb1, char *nb2);
char *my_infin_div(char *nb1, char *nb2);
char *my_infin_mod(char *nb1, char *nb2);
char *my_infin_sub(char *nb1, char *nb2);
char *my_infin_mult(char *nb1, char *nb2);
int is_nb1_greater(char *nb1, char *nb2);
char *reverse_and_calc(char *nb1, char *nb2, int neg1, int neg2);
char *clean_zeros(char *nbr_in_str);
int sub_nbrs(int nb1, int nb2, int neg1, int neg2);
int add_nbrs(int nb1, int nb2, int neg1, int neg2);
char *calculate_sub(char *nb1, char *nb2, int neg1, int neg2);
char *calculate_add(char *nb1, char *nb2);
int is_nb1_greater(char *nb1, char *nb2);
int get_sign(char *nb);
char *negate(char *str);
void get_token(char **str, pf_struct *elem);
void copy_oper(char **str, pf_struct *pf_s);
void copy_num(char **str, pf_struct *pf_s);

#endif