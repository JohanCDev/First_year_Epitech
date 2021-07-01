/*
** EPITECH PROJECT, 2020
** LibMy - parsing module
** File description:
** parsing module configuration
*/

#ifndef __LIBMY_PARSING_CONFIG_H__
#define __LIBMY_PARSING_CONFIG_H__

#include "libmy/config.h"
#include "libmy/internal/attributes.h"

#if defined(LIBMY_PARSING_EXPORTS)
    #define MY_PARSING_API MY_API_EXPORT
#else
    #define MY_PARSING_API MY_API_IMPORT
#endif // defined(LIBMY_PARSING_EXPORTS)

#endif // !defined(__LIBMY_PARSING_CONFIG_H__)
