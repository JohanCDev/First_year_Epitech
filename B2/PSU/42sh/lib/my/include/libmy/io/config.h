/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** io module configuration
*/

#ifndef __LIBMY_IO_CONFIG_H__
#define __LIBMY_IO_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_IO_EXPORTS)
    #define MY_IO_API MY_API_EXPORT
#else
    #define MY_IO_API MY_API_IMPORT
#endif // defined(LIBMY_IO_EXPORTS)

#endif // !defined(__LIBMY_IO_CONFIG_H__)
