/*
** EPITECH PROJECT, 2021
** pflag_iminmax.c
** File description:
** 4 - Options -p -imin/max
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_criterion_listener(void);

int entry_point(int argc, char **argv);

Test(pflag_iminmax_tests, imin_base_ten_a_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "1000000001", "-b", "10", "-imin", "1"
    };

    entry_point(7, argv);

    char *str = "1000000000 leads to 1000000001 in 1 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imin_imax_base_ten_b_test, .init = my_criterion_listener)
{

    char *argv[] = {
        "./palindrome", "-p", "363", "-b", "10", "-imin", "4", "-imax", "5"
    };

    entry_point(9, argv);

    char *str = "6 leads to 363 in 5 iteration(s) in base 10\n"
                "12 leads to 363 in 4 iteration(s) in base 10\n"
                "21 leads to 363 in 4 iteration(s) in base 10\n"
                "30 leads to 363 in 4 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imin_base_ten_c_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "363", "-b", "10", "-imin", "5"
    };

    entry_point(7, argv);

    char *str = "3 leads to 363 in 6 iteration(s) in base 10\n"
                "6 leads to 363 in 5 iteration(s) in base 10\n";

    cr_assert_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imax_base_ten_d_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "363", "-b", "10", "-imax", "0"
    };

    entry_point(7, argv);

    char *str = "363 leads to 363 in 0 iteration(s) in base 10\n";

    cr_assert_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imin_imax_base_ten_e_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "3663", "-b", "10", "-imin", "1", "-imax", "2"
    };

    entry_point(9, argv);

    char *str = "369 leads to 3663 in 2 iteration(s) in base 10\n"
                "468 leads to 3663 in 2 iteration(s) in base 10\n"
                "567 leads to 3663 in 2 iteration(s) in base 10\n"
                "666 leads to 3663 in 2 iteration(s) in base 10\n"
                "765 leads to 3663 in 2 iteration(s) in base 10\n"
                "864 leads to 3663 in 2 iteration(s) in base 10\n"
                "963 leads to 3663 in 2 iteration(s) in base 10\n"
                "1062 leads to 3663 in 1 iteration(s) in base 10\n"
                "1152 leads to 3663 in 1 iteration(s) in base 10\n"
                "1242 leads to 3663 in 1 iteration(s) in base 10\n"
                "1332 leads to 3663 in 1 iteration(s) in base 10\n"
                "1422 leads to 3663 in 1 iteration(s) in base 10\n"
                "1512 leads to 3663 in 1 iteration(s) in base 10\n"
                "1602 leads to 3663 in 1 iteration(s) in base 10\n"
                "2061 leads to 3663 in 1 iteration(s) in base 10\n"
                "2151 leads to 3663 in 1 iteration(s) in base 10\n"
                "2241 leads to 3663 in 1 iteration(s) in base 10\n"
                "2331 leads to 3663 in 1 iteration(s) in base 10\n"
                "2421 leads to 3663 in 1 iteration(s) in base 10\n"
                "2511 leads to 3663 in 1 iteration(s) in base 10\n"
                "2601 leads to 3663 in 1 iteration(s) in base 10\n"
                "3060 leads to 3663 in 1 iteration(s) in base 10\n"
                "3150 leads to 3663 in 1 iteration(s) in base 10\n"
                "3240 leads to 3663 in 1 iteration(s) in base 10\n"
                "3330 leads to 3663 in 1 iteration(s) in base 10\n"
                "3420 leads to 3663 in 1 iteration(s) in base 10\n"
                "3510 leads to 3663 in 1 iteration(s) in base 10\n"
                "3600 leads to 3663 in 1 iteration(s) in base 10\n";

    cr_assert_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imin_base_three_f_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "20", "-b", "3", "-imin", "2"
    };

    entry_point(7, argv);

    char *str = "9 leads to 20 in 2 iteration(s) in base 3\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imax_base_three_g_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "20", "-b", "3", "-imax", "1"
    };

    entry_point(7, argv);

    char *str = "10 leads to 20 in 1 iteration(s) in base 3\n"
                "18 leads to 20 in 1 iteration(s) in base 3\n"
                "20 leads to 20 in 0 iteration(s) in base 3\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_iminmax_tests, imin_imax_base_three_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "4", "-b", "3", "-imax", "3", "-imin", "3"
    };

    entry_point(9, argv);

    char *str = "no solution\n";

    cr_expect_stdout_eq_str(str);
}
