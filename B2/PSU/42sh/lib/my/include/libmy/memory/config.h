/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** memory module configuration
*/

#ifndef __LIBMY_MEMORY_CONFIG_H__
#define __LIBMY_MEMORY_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_MEMORY_EXPORTS)
    #define MY_MEMORY_API MY_API_EXPORT
#else
    #define MY_MEMORY_API MY_API_IMPORT
#endif // defined(LIBMY_MEMORY_EXPORTS)

#endif // !defined(__LIBMY_MEMORY_CONFIG_H__)
