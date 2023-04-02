/*
** EPITECH PROJECT, 2021
** requirement.c
** File description:
** 0 - Requirement
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <limits.h>

void my_criterion_listener(void);

int my_factrec_synthesis(int nb);

int my_squareroot_synthesis(int nb);

Test(requirement_tests, my_factrec_synthesis, .init = my_criterion_listener)
{
    cr_assert(my_factrec_synthesis(-1) == 0);
    cr_assert(my_factrec_synthesis(13) == 0);

    cr_assert(my_factrec_synthesis(0) == 1);
    cr_assert(my_factrec_synthesis(3) == 6);
    cr_assert(my_factrec_synthesis(4) == 24);
    cr_assert(my_factrec_synthesis(5) == 120);
    cr_assert(my_factrec_synthesis(6) == 720);
    cr_assert(my_factrec_synthesis(7) == 5040);
    cr_assert(my_factrec_synthesis(8) == 40320);
    cr_assert(my_factrec_synthesis(9) == 362880);
    cr_assert(my_factrec_synthesis(10) == 3628800);
    cr_assert(my_factrec_synthesis(11) == 39916800);
    cr_assert(my_factrec_synthesis(12) == 479001600);
}

Test(requirement_tests, my_squareroot_synthesis, .init = NULL)
{
    cr_assert(my_squareroot_synthesis(-1) == -1);
    cr_assert(my_squareroot_synthesis(INT_MAX) == -1);

    cr_assert(my_squareroot_synthesis(2) == -1);
    cr_assert(my_squareroot_synthesis(2 * 2) == 2);
    cr_assert(my_squareroot_synthesis(INT_MAX) == -1);
}
