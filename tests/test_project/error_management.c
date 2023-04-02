/*
** EPITECH PROJECT, 2021
** error_management.c
** File description:
** 5 - Error management
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_criterion_listener(void);

int entry_point(int argc, char **argv);

Test(error_management_tests, nwithout_value_a_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n"
    };

    entry_point(2, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_argument_b_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "HAAAAAAAAAAAAAA"
    };

    entry_point(3, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_option_c_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-HAAAAAAAAAAAAA", "12"
    };

    entry_point(3, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_base_d_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-b", "-1"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_base_e_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-b", "1"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_base_f_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-b", "16"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, n_and_p_conflict_g_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "101", "-p", "10"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, pwithout_value_h_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p"
    };

    entry_point(2, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, imin_neg_i_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "12", "-imin", "-12"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, imax_neg_j_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "12", "-imax", "-12"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, imin_bigger_than_imax_k_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "12", "-imin", "12", "-imax", "2"
    };

    entry_point(7, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_imin_l_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "12", "-imin", "HAAAAAAAAAAAA"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}

Test(error_management_tests, invalid_imax_m_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "12", "-imax", "10000000001"
    };

    entry_point(5, argv);

    cr_expect_stderr_eq_str("invalid argument\n");
}
