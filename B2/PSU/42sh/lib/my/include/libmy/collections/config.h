/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** collections module configuration
*/

#ifndef __LIBMY_COLLECTIONS_CONFIG_H__
#define __LIBMY_COLLECTIONS_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_COLLECTIONS_EXPORTS)
    #define MY_COLLECTIONS_API MY_API_EXPORT
#else
    #define MY_COLLECTIONS_API MY_API_IMPORT
#endif // defined(LIBMY_COLLECTIONS_EXPORTS)

#endif // !defined(__LIBMY_COLLECTIONS_CONFIG_H__)
