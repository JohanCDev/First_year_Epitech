/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** convert_to_base
*/

#include "pal.h"
#include "my.h"
#include <stdlib.h>

int check_before_starting_conversion_to_base(char *str_to_return, int number)
{
    if (str_to_return == NULL)
        return my_put_error("Error malloc\n", -1);
    if (number == -1)
        return my_put_error("Invalid number\n", -1);
    return 0;
}

char *my_convert_int_to_base(int number, char const *base)
{
    int res = 0;
    int pow = 1;
    int base_size = my_strlen(base);
    int count = 0;
    char *str_to_return = malloc(sizeof(char) * 100);
    char *str_to_return_tmp = NULL;

    if (check_before_starting_conversion_to_base(str_to_return, number) == -1)
        return NULL;
    while ((number / pow) >= base_size)
        pow *= base_size;
    while (pow > 0) {
        res = (number / pow) % base_size;
        str_to_return[count++] = base[res];
        pow = pow / base_size;
    }
    str_to_return[count] = 0;
    str_to_return_tmp = my_strdup(str_to_return);
    my_free(str_to_return);
    return str_to_return_tmp;
}

char *change_base_from_dec(int nb, int base)
{
    switch (base) {
    case 2:
        return my_convert_int_to_base(nb, "01");
    case 3:
        return my_convert_int_to_base(nb, "012");
    case 4:
        return my_convert_int_to_base(nb, "0123");
    case 5:
        return my_convert_int_to_base(nb, "01234");
    case 6:
        return my_convert_int_to_base(nb, "012345");
    case 7:
        return my_convert_int_to_base(nb, "0123456");
    case 8:
        return my_convert_int_to_base(nb, "01234567");
    case 9:
        return my_convert_int_to_base(nb, "012345678");
    default:
        return my_convert_int_to_base(nb, "0123456789");
    }
}