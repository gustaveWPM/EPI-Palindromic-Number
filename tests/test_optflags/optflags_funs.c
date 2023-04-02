/*
** EPITECH PROJECT, 2021
** optflags_funs.c
** File description:
** Optflags funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <unistd.h>

#include "my_optflags.h"
#include "my_two_dims_arrays.h"

#include "my_iostring.h"
#include "my_optflags_debug.h"

#include "my_linked_list.h"
#include "my_linked_lists_debug.h"

#include "my_string.h"

void my_criterion_listener(void);

/* ... {ToDo/REM} No flag precedences handling required for this project
Test(optflags_test, medium_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./a.out", "--prec-test", "10", "--next", "12", "--prec-test", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[ERROR] WRONG FLAGS PRECEDENCES: --prec-test SHOULD PRECEDE --next\n"
    );
}
*/

/* ... {ToDo/REM} Can't test fetchall here because all flags are uniq
Test(optflags_test, dummy_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./a.out", "-test", "hello\n", "-test", "i\n",
        "-test", "-test", "ponies\n", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);
    if (!opt)
        cr_assert_fail("Failed to malloc or invalid opt.\n");
    node_t *values = my_fetchall_flag_values(opt, "-test");
    if (!values)
        cr_assert_fail("Failed to malloc.\n");
    node_t *cur_node = values;
    char *cur_str = NULL;

    print_list(values, print_str);
    cr_assert_stdout_eq_str("hello\ni\nponies\n");
    cur_str = values->next->next->data;
    cr_assert(my_is_empty_str(cur_str));
    my_linked_list_destroyer(&values);
}
*/

/* ... {ToDo/REM} Can't test fetchall here because all flags are uniq
Test(optflags_test, fetchall_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./a.out", "-z", "hello\n", "-z",
        "-p", "hello!\n", "-p", "hi!", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, false);
    node_t *list_a = my_fetchall_flag_values(opt, "-z");
    node_t *list_b = my_fetchall_flag_values(opt, "-p");

    if (!list_a || !list_b) {
        if (list_a)
            my_linked_list_destroyer(&list_a);
        if (list_b)
            my_linked_list_destroyer(&list_b);
        cr_assert_fail("Failed to malloc.\n");
    }
    print_list(list_a, print_str);
    print_list(list_b, print_str);
    my_optflags_destroy(&opt);
    my_linked_list_destroyer(&list_a);
    my_linked_list_destroyer(&list_b);
    cr_assert_stdout_eq_str("hello\nhello!\nhi!");
}
*/

Test(optflags_test, no_strict_mode_verb_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "test", "10", "-dummy", "-dunno", "25", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    if (!opt)
        cr_assert_fail("Failed to malloc or invalid opt.\n");
    display_tassoc(opt);
    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[WARNING] UNEXPECTED TOKEN: test\n"
        "[WARNING] UNEXPECTED TOKEN: 10\n"
        "[WARNING] UNKNOWN FLAG: -dummy\n"
        "[WARNING] UNKNOWN FLAG: -dunno\n"
        "Flag n°0: -dummy\n"
        "Value n°0: NULL\n"
        "Flag n°1: -dunno\n"
        "Value n°1: 25\n"
    );
}

Test(optflags_test, no_strict_mode_noverb_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "test", "10", "-dummy", "-dunno", "25", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, false);

    if (!opt)
        cr_assert_fail("Failed to malloc or invalid opt.\n");
    display_tassoc(opt);
    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "Flag n°0: -dummy\n"
        "Value n°0: NULL\n"
        "Flag n°1: -dunno\n"
        "Value n°1: 25\n"
    );
}

Test(optflags_test, strict_mode_verb_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "test", "10", "-dummy", "-dunno", "25", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, true, true);

    display_tassoc(opt);
    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[ERROR] UNEXPECTED TOKEN: test\n"
        "[ERROR] UNEXPECTED TOKEN: 10\n"
    );
}

Test(optflags_test, strict_mode_silent_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "test", "10", "-dummy", "-dunno", "25", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);

    cr_assert(!my_optflags_builder(argc, argv, true, false));
    dprintf(STDERR_FILENO, "NOT VERBOSE");
    cr_assert_stderr_eq_str("NOT VERBOSE");
}

Test(optflags_test, strict_mode_verb_deuz_test, .init = my_criterion_listener)
{
    char *argv[] = {"./palindrome", "-n", "4", "-b", "10", "test", "10", "-lulz", NULL};
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, true, true);

    display_tassoc(opt);
    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[ERROR] UNEXPECTED TOKEN: test\n"
        "[ERROR] UNEXPECTED TOKEN: 10\n"
    );
}

Test(optflags_test, ez_mode_verb_deuz_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-dummy", "-dunno", "test", "test", "10", "-lulz", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    if (!opt)
        cr_assert_fail("Failed to malloc or invalid opt.\n");
    display_tassoc(opt);
    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[WARNING] UNEXPECTED TOKEN: test\n"
        "[WARNING] UNEXPECTED TOKEN: 10\n"
        "[WARNING] UNKNOWN FLAG: -dummy\n"
        "[WARNING] UNKNOWN FLAG: -dunno\n"
        "[WARNING] UNKNOWN FLAG: -lulz\n"
        "Flag n°0: -dummy\n"
        "Value n°0: NULL\n"
        "Flag n°1: -dunno\n"
        "Value n°1: test\n"
        "Flag n°2: -lulz\n"
        "Value n°2: NULL\n"
    );
}

Test(optflags_test, incompatible_flags_silent_test, .init = NULL)
{
    char *argv[] = {
        "./palindrome", "-p", "4", "-n", "8", "-b", "8", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, false);

    cr_assert(!opt);
}

Test(optflags_test, incompatible_flag_verb_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-p", "4", "-n", "8", "-b", "8", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    cr_assert(!opt);
    cr_assert_stderr_eq_str("[ERROR] INCOMPATIBLE FLAGS: -n, -p\n");
}

Test(optflags_test, basic_test, .init = NULL)
{
    char *argv[] = {"./palindrome", NULL};
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    cr_assert(!opt);
}

Test(optflags_test, advanced_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-n", "4", "-n", "4", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[ERROR] THIS FLAG SHOULD BE UNIQ: -n\n"
    );
}

Test(optflags_test, fetch_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "--dump", "hello\n", "-z", "world?\n", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, false);

    if (!opt)
        cr_assert_fail("Failed to malloc or invalid opt.\n");
    my_puterr(my_fetch_first_flag_value(opt, "--dump"));
    my_puterr(my_fetch_first_flag_value(opt, "-z"));
    cr_assert_stderr_eq_str("hello\nworld?\n");
    my_optflags_destroy(&opt);
}

Test(optflags_test, req_value_test, .init = my_criterion_listener)
{
    char *argv[] = {
        "./palindrome", "-z", "hello\n", "-z",
        "-n", "-imax", NULL
    };
    int argc = (int) my_two_dims_array_len((void **) argv);
    optflags_t *opt = my_optflags_builder(argc, argv, false, true);

    my_optflags_destroy(&opt);
    cr_assert_stderr_eq_str(
        "[WARNING] UNKNOWN FLAG: -z\n"
        "[ERROR] THIS FLAG REQUIRES A VALUE: -n\n"
        "[ERROR] THIS FLAG REQUIRES A VALUE: -imax\n"
    );
}
