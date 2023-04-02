/*
** EPITECH PROJECT, 2021
** pflag.c
** File description:
** 3 - Option -p
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_criterion_listener(void);

int entry_point(int argc, char **argv);

Test(pflag_tests, base_ten_a_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "1000000001"
    };

    entry_point(3, argv);

    char *str = "1000000000 leads to 1000000001 in 1 iteration(s) in base 10\n"
                "1000000001 leads to 1000000001 in 0 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_ten_b_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "202"
    };

    entry_point(3, argv);

    char *str = "100 leads to 202 in 2 iteration(s) in base 10\n"
                "101 leads to 202 in 1 iteration(s) in base 10\n"
                "200 leads to 202 in 1 iteration(s) in base 10\n"
                "202 leads to 202 in 0 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_ten_c_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "12321"
    };

    entry_point(3, argv);

    char *str = "12321 leads to 12321 in 0 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_ten_d_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "404"
    };

    entry_point(3, argv);

    char *str = "100 leads to 404 in 3 iteration(s) in base 10\n"
                "101 leads to 404 in 2 iteration(s) in base 10\n"
                "103 leads to 404 in 1 iteration(s) in base 10\n"
                "200 leads to 404 in 2 iteration(s) in base 10\n"
                "202 leads to 404 in 1 iteration(s) in base 10\n"
                "301 leads to 404 in 1 iteration(s) in base 10\n"
                "400 leads to 404 in 1 iteration(s) in base 10\n"
                "404 leads to 404 in 0 iteration(s) in base 10\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_nine_e_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "82", "-b", "9"
    };

    entry_point(5, argv);

    char *str = "81 leads to 82 in 1 iteration(s) in base 9\n"
                "82 leads to 82 in 0 iteration(s) in base 9\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_three_f_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "20", "-b", "3"
    };

    entry_point(5, argv);

    char *str = "9 leads to 20 in 2 iteration(s) in base 3\n"
                "10 leads to 20 in 1 iteration(s) in base 3\n"
                "18 leads to 20 in 1 iteration(s) in base 3\n"
                "20 leads to 20 in 0 iteration(s) in base 3\n";

    cr_expect_stdout_eq_str(str);
}

Test(pflag_tests, base_six_g_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "37", "-b", "6"
    };

    entry_point(5, argv);

    char *str = "36 leads to 37 in 1 iteration(s) in base 6\n"
                "37 leads to 37 in 0 iteration(s) in base 6\n";

    cr_expect_stdout_eq_str(str);
}
