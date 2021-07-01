/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Fills the args array from types and a va_list
*/

#include <sys/types.h>

#include "libmy/printf.h"
#include "my_printf.h"

static uintmax_t p_my_printf_get_uint_arg(
    p_my_printf_arg_type_t type, va_list va_args)
{
    switch (type) {
        case P_MY_PRINTF_ARG_BYTE:
            return (uintmax_t)(unsigned char)va_arg(va_args, unsigned int);
        case P_MY_PRINTF_ARG_USHORT:
            return (uintmax_t)(unsigned short)va_arg(va_args, unsigned int);
        case P_MY_PRINTF_ARG_ULONG:
            return (uintmax_t)va_arg(va_args, unsigned long);
        case P_MY_PRINTF_ARG_ULONG_LONG:
            return (uintmax_t)va_arg(va_args, unsigned long long);
        case P_MY_PRINTF_ARG_UINTMAX_T: return va_arg(va_args, intmax_t);
        case P_MY_PRINTF_ARG_SIZE_T: return (uintmax_t)va_arg(va_args, size_t);
        case P_MY_PRINTF_ARG_UPTRDIFF_T:
            return (uintmax_t)va_arg(va_args, ptrdiff_t);
        default: return (uintmax_t)va_arg(va_args, unsigned int);
    }
}

static uintmax_t p_my_printf_get_sint_arg(
    p_my_printf_arg_type_t type, va_list va_args)
{
    switch (type) {
        case P_MY_PRINTF_ARG_SBYTE:
            return (intmax_t)(signed char)va_arg(va_args, int);
        case P_MY_PRINTF_ARG_SHORT:
            return (intmax_t)(short)va_arg(va_args, int);
        case P_MY_PRINTF_ARG_LONG: return (intmax_t)va_arg(va_args, long);
        case P_MY_PRINTF_ARG_LONG_LONG:
            return (intmax_t)va_arg(va_args, long long);
        case P_MY_PRINTF_ARG_INTMAX_T: return va_arg(va_args, intmax_t);
        case P_MY_PRINTF_ARG_SSIZE_T:
            return (intmax_t)va_arg(va_args, ssize_t);
        case P_MY_PRINTF_ARG_PTRDIFF_T:
            return (intmax_t)va_arg(va_args, ptrdiff_t);
        default: return (intmax_t)va_arg(va_args, int);
    }
}

static void p_my_printf_fill_int_arg(
    p_my_printf_arg_t *arg, p_my_printf_arg_type_t *type, va_list va_args)
{
    if (*type & 1) {
        arg->uint_arg = p_my_printf_get_uint_arg(*type, va_args);
        *type = P_MY_PRINTF_ARG_UINTMAX_T;
    } else {
        arg->sint_arg = p_my_printf_get_sint_arg(*type, va_args);
        *type = P_MY_PRINTF_ARG_INTMAX_T;
    }
}

static void p_my_printf_fill_arg(
    p_my_printf_arg_t *arg, p_my_printf_arg_type_t *type, va_list va_args)
{
    switch (*type) {
        case P_MY_PRINTF_ARG_CHAR:
            arg->char_arg = (char)va_arg(va_args, unsigned int);
            break;
        case P_MY_PRINTF_ARG_DOUBLE:
            arg->double_arg = va_arg(va_args, double);
            break;
        case P_MY_PRINTF_ARG_LONG_DOUBLE:
            arg->long_double_arg = va_arg(va_args, long double);
            break;
        case P_MY_PRINTF_ARG_PERCENT: break;
        default: p_my_printf_fill_int_arg(arg, type, va_args);
    }
}

MY_LOCAL void p_my_printf_fill_args(size_t count, p_my_printf_arg_t args[],
    p_my_printf_arg_type_t types[], va_list va_args)
{
    for (size_t i = 0; i < count; ++i) {
        switch (types[i]) {
            case P_MY_PRINTF_ARG_STRING:
            case P_MY_PRINTF_ARG_POINTER:
            case P_MY_PRINTF_ARG_PTR_SCHAR:
            case P_MY_PRINTF_ARG_PTR_SHORT:
            case P_MY_PRINTF_ARG_PTR_INT:
            case P_MY_PRINTF_ARG_PTR_LONG:
            case P_MY_PRINTF_ARG_PTR_LONG_LONG:
            case P_MY_PRINTF_ARG_PTR_INTMAX_T:
            case P_MY_PRINTF_ARG_PTR_SIZE_T:
            case P_MY_PRINTF_ARG_PTR_PTRDIFF_T:
                args[i].pointer_arg = va_arg(va_args, void const *);
                break;
            default: p_my_printf_fill_arg(args + i, types + i, va_args);
        }
    }
}
