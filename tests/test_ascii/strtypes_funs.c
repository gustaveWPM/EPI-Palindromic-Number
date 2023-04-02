/*
** EPITECH PROJECT, 2021
** str_funs.c
** File description:
** Str funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_strtypes.h"

#include <unistd.h>

Test(strtypes_funs_tests, my_isalpha_test, .init = NULL)
{
    cr_assert(!my_isalpha("B2"));
    cr_assert(!my_isalpha(NULL));

    cr_assert(my_isalpha("AHA"));
    cr_assert(my_isalpha("AhA"));
}

Test(strtypes_funs_tests, my_isdigit_test, .init = NULL)
{
    cr_assert(!my_isdigit("2B2"));
    cr_assert(!my_isdigit(NULL));

    cr_assert(my_isdigit("123"));
}

Test(strtypes_funs_tests, my_islower_test, .init = NULL)
{
    cr_assert(!my_islower("aBa"));
    cr_assert(!my_islower(NULL));

    cr_assert(my_islower("abc"));
}

Test(strtypes_funs_tests, my_isupper_test, .init = NULL)
{
    cr_assert(!my_isupper("aBa"));
    cr_assert(!my_isupper(NULL));

    cr_assert(my_isupper("ABC"));
}

Test(strtypes_funs_tests, my_isalphanum_test, .init = NULL)
{
    cr_assert(!my_isalphanum("Ab0_"));
    cr_assert(!my_isalphanum(NULL));

    cr_assert(my_isalphanum("Ab1"));
}

Test(strtypes_funs_tests, my_isprintable_test, .init = NULL)
{
    char test_str[4] = "AAA";

    test_str[2] = 8;
    cr_assert(!my_is_printable(test_str));
    cr_assert(my_is_printable("Ab0_"));
}
