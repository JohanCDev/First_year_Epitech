/*
** EPITECH PROJECT, 2020
** LibMy - hash module
** File description:
** hash module configuration
*/

#ifndef __LIBMY_HASH_CONFIG_H__
#define __LIBMY_HASH_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_HASH_EXPORTS)
    #define MY_HASH_API MY_API_EXPORT
#else
    #define MY_HASH_API MY_API_IMPORT
#endif // defined(LIBMY_HASH_EXPORTS)

#endif // !defined(__LIBMY_HASH_CONFIG_H__)
