/*
** EPITECH PROJECT, 2020
** test_my_isneg
** File description:
** test for my_isneg 
*/
extern void my_putchar(char c);
extern int my_isneg(int nb);

int main(void)
{
    my_isneg(0);
    my_isneg(34);
    my_isneg(-52);
    my_isneg(2147483647);
    my_isneg(-2147483647);
}
