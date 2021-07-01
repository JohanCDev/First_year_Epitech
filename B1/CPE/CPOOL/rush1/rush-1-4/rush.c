/*
** EPITECH PROJECT, 2020
** rush1.4
** File description:
** A left corners C right corners B lines
*/
void my_putchar(char c);

void print_first_h_line(int x, int y)
{
    if (y != 1) {
        my_putchar(65);
        for (int i = 0; i < x - 2; i++) {
            my_putchar(66);
        }
        if (x != 1) {
            my_putchar(67);
        }
    } else {
        for (int i = 0; i < x; i++) {
            my_putchar(66);
        }
    }
    my_putchar(10);
}

void print_last_h_line(int x)
{
    my_putchar(65);
    for (int i = 0; i < x - 2; i++) {
        my_putchar(66);
    }
    if (x != 1) {
        my_putchar(67);
    }
    my_putchar(10);
}

void print_v_line(int x)
{
    if (x != 1) {
        my_putchar(66);
        for (int i = 0; i < x - 2; i++) {
            my_putchar(32);
        }
        if (x != 1) {   
            my_putchar(66);
        }
    } else {
        my_putchar(66);
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

void print_square(int x, int y)
{
    if (x == 1) {
        for (int i = 0; i < y; i++) {
            print_v_line(x);
        }
    } else {
        print_first_h_line(x, y);
        for (int i = 0; i < y - 2; i++) {
            print_v_line(x);
        }
        if (y != 1) {
            print_last_h_line(x);
        }
    }
}

void rush(int x, int y)
{
    if (x > 0 && y > 0) {
        print_square(x, y);
    } else {
        print_error_size();
    }
}
