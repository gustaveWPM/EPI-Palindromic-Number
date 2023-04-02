/*
** EPITECH PROJECT, 2021
** requirement.c
** File description:
** Project Requirement file
*/

#include "./mylib/headers/maths/my_maths_consts.h"

int my_factrec_synthesis(int nb)
{
    if (nb > MATHS_CONSTS.MAX_IFACTORIAL_ARG_NB || nb < 0)
        return 0;
    if (nb == 0)
        return 1;
    return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int start = 1;
    int end = nb;
    int mid = 0;

    if (nb < 0)
        return -1;
    if (nb == 0 || nb == 1)
        return nb;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == nb)
            return mid;
        if (mid <= nb / mid)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
