/*
** EPITECH PROJECT, 2021
** char_funs.c
** File description:
** Char funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_maths.h"
#include "my_string.h"

#include <stdio.h>
#include <unistd.h>

void my_criterion_listener(void);

Test(maths_funs_test, test_parity, .init = NULL)
{
    cr_assert(!MY_ISODD(2));
    cr_assert(!MY_ISEVEN(1));

    cr_assert(MY_ISODD(-1));
    cr_assert(MY_ISEVEN(-2));
}

Test(maths_funs_test, test_sqrt, .init = NULL)
{
    cr_assert(my_sqrt_i(25) == 5);
    cr_assert(my_sqrt_i(4) == 2);
    cr_assert(my_sqrt_i(1) == 1);
    cr_assert(my_sqrt_i(-1) == -1);
    cr_assert(my_sqrt_i(1000) == -1);
}

Test(maths_funs_test, test_abs, .init = NULL)
{
    cr_assert(my_abs_c(25) == 25);
    cr_assert(my_abs_i(2500) == 2500);
    cr_assert(my_abs_ld(821938) == 821938);
    cr_assert(my_abs(829138921381) == 829138921381);

    cr_assert(my_abs_c(-25) == 25);
    cr_assert(my_abs_i(-2500) == 2500);
    cr_assert(my_abs_ld(-821938) == 821938);
    cr_assert(my_abs(-829138921381) == 829138921381);
}

Test(maths_funs_test, test_pow, .init = my_criterion_listener)
{
    float pow_res = 0.0f;

    cr_assert(my_pow(2, -4) == 0.0625f);
    cr_assert(my_pow(2, 4) == 16);
    pow_res = my_pow(2.2, 4);
    dprintf(STDOUT_FILENO, "%g", pow_res);
    cr_assert_stdout_eq_str("23.4256");
}

Test(maths_funs_test, test_fact, .init = NULL)
{
    cr_assert(my_ifactorial(-1) == 0);
    cr_assert(my_ifactorial(0) == 1);
    cr_assert(my_ifactorial(1) == 1);
    cr_assert(my_ifactorial(2) == 2);
    cr_assert(my_ifactorial(3) == 6);
    cr_assert(my_ifactorial(4) == 24);
    cr_assert(my_ifactorial(5) == 120);
    cr_assert(my_ifactorial(6) == 720);
    cr_assert(my_ifactorial(7) == 5040);
    cr_assert(my_ifactorial(8) == 40320);
    cr_assert(my_ifactorial(9) == 362880);
    cr_assert(my_ifactorial(10) == 3628800);
    cr_assert(my_ifactorial(11) == 39916800);
    cr_assert(my_ifactorial(12) == 479001600);
    cr_assert(my_ifactorial(13) == 0);
    cr_assert(my_ifactorial(40) == 0);
}

Test(maths_funs_test, test_itobase, .init = NULL)
{
    char *to_base = my_itobase(64, 16);

    if (!to_base)
        cr_assert_fail("Failed to malloc\n");
    cr_assert(!my_strcmp("40", to_base));
    free(to_base);
    to_base = my_itobase(64, 2);
    if (!to_base)
        cr_assert_fail("Failed to malloc\n");
    cr_assert(!my_strcmp("1000000", to_base));
    free(to_base);
    to_base = my_itobase(64, 10);
    if (!to_base)
        cr_assert_fail("Failed to malloc\n");
    cr_assert(!my_strcmp("64", to_base));
    free(to_base);
}

Test(maths_funs_test, test_revint, .init = NULL)
{
    cr_assert(my_revint(4138) == 8314);
    cr_assert(my_revint(-4138) == -8314);
    cr_assert(my_revint(1) == 1);
    cr_assert(my_revint(-1) == -1);
}

Test(maths_funs_test, test_basetoi, .init = NULL)
{
    cr_assert(my_basetoi("00000", 1) == -1);
    cr_assert(my_basetoi("1020", 2) == -1);
    cr_assert(my_basetoi("103", 3) == -1);
    cr_assert(my_basetoi("24", 4) == -1);
    cr_assert(my_basetoi("25", 5) == -1);
    cr_assert(my_basetoi("16", 6) == -1);
    cr_assert(my_basetoi("17", 7) == -1);
    cr_assert(my_basetoi("18", 8) == -1);
    cr_assert(my_basetoi("19", 9) == -1);
    cr_assert(my_basetoi("A", 10) == -1);
    cr_assert(my_basetoi("B", 11) == -1);
    cr_assert(my_basetoi("C", 12) == -1);
    cr_assert(my_basetoi("D", 13) == -1);
    cr_assert(my_basetoi("E", 14) == -1);
    cr_assert(my_basetoi("F", 15) == -1);
    cr_assert(my_basetoi("G", 16) == -1);

    cr_assert(my_basetoi(NULL, 1) == -1);
    cr_assert(my_basetoi(NULL, 2) == -1);
    cr_assert(my_basetoi(NULL, 3) == -1);
    cr_assert(my_basetoi(NULL, 4) == -1);
    cr_assert(my_basetoi(NULL, 5) == -1);
    cr_assert(my_basetoi(NULL, 6) == -1);
    cr_assert(my_basetoi(NULL, 7) == -1);
    cr_assert(my_basetoi(NULL, 8) == -1);
    cr_assert(my_basetoi(NULL, 9) == -1);
    cr_assert(my_basetoi(NULL, 10) == -1);
    cr_assert(my_basetoi(NULL, 11) == -1);
    cr_assert(my_basetoi(NULL, 12) == -1);
    cr_assert(my_basetoi(NULL, 13) == -1);
    cr_assert(my_basetoi(NULL, 14) == -1);
    cr_assert(my_basetoi(NULL, 15) == -1);
    cr_assert(my_basetoi(NULL, 16) == -1);
    cr_assert(my_basetoi(NULL, 17) == -1);

    cr_assert(my_basetoi("1010", 2) == 10);
    cr_assert(my_basetoi("101", 3) == 10);
    cr_assert(my_basetoi("22", 4) == 10);
    cr_assert(my_basetoi("20", 5) == 10);
    cr_assert(my_basetoi("14", 6) == 10);
    cr_assert(my_basetoi("13", 7) == 10);
    cr_assert(my_basetoi("12", 8) == 10);
    cr_assert(my_basetoi("11", 9) == 10);
    cr_assert(my_basetoi("10", 10) == 10);
    cr_assert(my_basetoi("A", 11) == 10);
    cr_assert(my_basetoi("75A2", 12) == 12938);
    cr_assert(my_basetoi("75a2", 12) == 12938);
    cr_assert(my_basetoi("59B8B7", 13) == 2139183);
    cr_assert(my_basetoi("1361B94BD", 14) == 1838192831);
    cr_assert(my_basetoi("1208808", 15) == 12938183);
    cr_assert(my_basetoi("8B49C7", 16) == 9128391);

    cr_assert(my_basetoi("84D5E82DE61DEFFF", 16) == -1);
}
