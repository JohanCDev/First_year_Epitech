/*
** EPITECH PROJECT, 2020
** rush1
** File description:
** o in corners - horizontal | vertical
*/
void my_putchar (char c);

void print_h_line(int x)
{
    my_putchar(111);
    for (int i = 0; i < x - 2; i++) {
        my_putchar(45);
    }
    if (x != 1) {
        my_putchar(111);
    }
    my_putchar(10);
}

void print_v_line(int x)
{
    my_putchar(124);
    for (int i = 0; i < x - 2; i++) {
        my_putchar(32);
    }
    if (x != 1) {   
        my_putchar(124);
    }
    my_putchar(10);
}

void print_error_size()
{
    my_putchar(73);
    my_putchar(110);
    my_putchar(118);
    my_putchar(97);
    my_putchar(108);
    my_putchar(105);
    my_putchar(100);
    my_putchar(32);
    my_putchar(115);
    my_putchar(105);
    my_putchar(122);
    my_putchar(101);
    my_putchar(10);
}

void rush(int x, int y)
{
    if (x > 0 && y > 0) {
        print_h_line(x);
        for (int i = 0; i < y - 2; i++) {
            print_v_line(x);
        }
        if (y != 1) {
            print_h_line(x);
        }
    } else {
        print_error_size();
    }
}
