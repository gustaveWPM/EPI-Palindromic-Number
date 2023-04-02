/*
** EPITECH PROJECT, 2021
** my_abs.c
** File description:
** Returns absolute values
*/

#include <stdint.h>

long long my_abs(long long x)
{
    if (x < 0)
        return -x;
    return x;
}

long my_abs_ld(long x)
{
    if (x < 0)
        return -x;
    return x;
}

int my_abs_i(int x)
{
    if (x < 0)
        return -x;
    return x;
}

int8_t my_abs_c(int8_t x)
{
    if (x < 0)
        return -x;
    return x;
}
