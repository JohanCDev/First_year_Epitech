/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** ascii module configuration
*/

#ifndef __LIBMY_ASCII_CONFIG_H__
#define __LIBMY_ASCII_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_ASCII_EXPORTS)
    #define MY_ASCII_API MY_API_EXPORT
#else
    #define MY_ASCII_API MY_API_IMPORT
#endif // defined(LIBMY_ASCII_EXPORTS)

#endif // !defined(__LIBMY_ASCII_CONFIG_H__)
