/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** printf module configuration
*/

#ifndef __LIBMY_PRINTF_CONFIG_H__
#define __LIBMY_PRINTF_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_PRINTF_EXPORTS)
    #define MY_PRINTF_API MY_API_EXPORT
#else
    #define MY_PRINTF_API MY_API_IMPORT
#endif // defined(LIBMY_PRINTF_EXPORTS)

#endif // !defined(__LIBMY_PRINTF_CONFIG_H__)
