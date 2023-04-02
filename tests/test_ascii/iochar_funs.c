/*
** EPITECH PROJECT, 2021
** iochar_funs.c
** File description:
** IO Char unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_iochar.h"

#include <unistd.h>

void my_criterion_listener(void);

Test(iochar_funs_tests, stdout_test, .init = my_criterion_listener)
{
    my_putchar('$');
    cr_assert_stdout_eq_str("$");
}

Test(iochar_funs_tests, stderr_test, .init = my_criterion_listener)
{
    my_putchar_err('$');
    cr_assert_stderr_eq_str("$");
}

Test(iochar_funs_tests, advanced_tests, .init = my_criterion_listener)
{
    my_putchar_err('$');
    my_dputchar(STDERR_FILENO, '@');
    cr_assert_stderr_eq_str("$@");

    my_putchar('!');
    my_dputchar(STDOUT_FILENO, '?');
    cr_assert_stdout_eq_str("!?");
}
