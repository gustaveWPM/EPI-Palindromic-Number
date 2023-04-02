/*
** EPITECH PROJECT, 2021
** my_safe_free.h
** File description:
** Safer free (because Dennis Ritchie is a fool)
*/

/*-*\
    ... Many thanks to L. B.
    who is the smartest programmer that's ever lived
\*-*/

#ifndef MY_SAFE_FREE
    #include <stdlib.h>

    #define MY_SAFE_FREE(ptr) \
    do { \
        free(ptr); \
        ptr = NULL; \
    } while (0)
#endif
