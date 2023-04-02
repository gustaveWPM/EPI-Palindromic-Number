/*
** EPITECH PROJECT, 2021
** my_ifactorial.c
** File description:
** Factorial function (integer only, as in Cpool)
*/

#include "my_maths_consts.h"

int my_ifactorial(int x)
{
    if (x > MATHS_CONSTS.MAX_IFACTORIAL_ARG_NB || x < 0)
        return 0;
    if (x == 0)
        return 1;
    return (x * my_ifactorial(x - 1));
}
