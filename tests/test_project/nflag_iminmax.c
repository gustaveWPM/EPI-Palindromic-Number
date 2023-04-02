/*
** EPITECH PROJECT, 2021
** nflag_iminmax.c
** File description:
** 2 - Options -n -imin/max
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_criterion_listener(void);

int entry_point(int argc, char **argv);

Test(nflag_iminmax_tests, imin_base_ten_a_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "4782", "-b", "10", "-imin", "3"
    };

    entry_point(7, argv);

    cr_assert_stdout_eq_str("4782 leads to 46464 in 3 iteration(s) in base 10\n");
}

Test(nflag_iminmax_tests, imin_base_ten_b_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "4782", "-b", "10", "-imin", "4"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("no solution\n");
}

Test(nflag_iminmax_tests, imin_base_five_c_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "48", "-b", "5", "-imin", "4"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("48 leads to 2448 in 4 iteration(s) in base 5\n");
}

Test(nflag_iminmax_tests, imin_ten_base_ten_d_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "48", "-b", "5", "-imin", "22"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("no solution\n");
}

Test(nflag_iminmax_tests, imax_base_ten_e_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "48", "-b", "5", "-imax", "3"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("no solution\n");
}

Test(nflag_iminmax_tests, imax_base_ten_f_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "48", "-b", "5", "-imax", "4"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("48 leads to 2448 in 4 iteration(s) in base 5\n");
}

Test(nflag_iminmax_tests, imax_base_five_g_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "1001", "-b", "5", "-imax", "1"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("1001 leads to 1642 in 1 iteration(s) in base 5\n");
}

Test(nflag_iminmax_tests, imax_no_solution_h_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "1001", "-b", "5", "-imax", "0"
    };

    entry_point(7, argv);

    cr_expect_stdout_eq_str("no solution\n");
}

Test(nflag_iminmax_tests, imin_imax_base_ten_i_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-b", "5", "-imin", "5", "-imax", "16"
    };

    entry_point(9, argv);

    cr_expect_stdout_eq_str("101 leads to 17555616 in 16 iteration(s) in base 5\n");
}

Test(nflag_iminmax_tests, imin_imax_base_four_j_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-b", "4", "-imin", "5", "-imax", "16"
    };

    entry_point(9, argv);

    cr_expect_stdout_eq_str("101 leads to 3935 in 6 iteration(s) in base 4\n");
}
