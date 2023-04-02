/*
** EPITECH PROJECT, 2021
** nflag.c
** File description:
** 1 - Option -n
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_criterion_listener(void);

int entry_point(int argc, char **argv);

Test(nflag_tests, no_base_a_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "4"
    };

    cr_assert(entry_point(3, argv) == 0);
    cr_assert_stdout_eq_str("4 leads to 4 in 0 iteration(s) in base 10\n");
}

Test(nflag_tests, base_ten_b_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "4", "-b", "10"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("4 leads to 4 in 0 iteration(s) in base 10\n");
}

Test(nflag_tests, no_base_c_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "3992"
    };

    cr_assert(entry_point(3, argv) == 0);
    cr_assert_stdout_eq_str("3992 leads to 293392 in 7 iteration(s) in base 10\n");
}

Test(nflag_tests, base_ten_d_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "30", "-b", "10"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("30 leads to 33 in 1 iteration(s) in base 10\n");
}

Test(nflag_tests, base_two_e_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "30", "-b", "2"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("30 leads to 45 in 1 iteration(s) in base 2\n");
}

Test(nflag_tests, base_five_f_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "30", "-b", "5"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("30 leads to 36 in 1 iteration(s) in base 5\n");
}

Test(nflag_tests, base_five_g_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "2", "-b", "5"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("2 leads to 2 in 0 iteration(s) in base 5\n");
}

Test(nflag_tests, base_five_h_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "3", "-b", "5"
    };

    cr_assert(entry_point(5, argv) == 0);
    cr_assert_stdout_eq_str("3 leads to 3 in 0 iteration(s) in base 5\n");
}
