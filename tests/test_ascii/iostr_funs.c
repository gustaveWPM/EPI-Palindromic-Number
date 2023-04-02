/*
** EPITECH PROJECT, 2021
** iostr_funs.c
** File description:
** IO Str funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_iostring.h"
#include "my_two_dims_arrays.h"

#include <unistd.h>

void my_criterion_listener(void);

Test(iostr_funs_tests, stdout_test, .init = my_criterion_listener)
{
    my_putstr("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(iostr_funs_tests, stderr_test, .init = my_criterion_listener)
{
    my_puterr("Hello world");
    cr_assert_stderr_eq_str("Hello world");
}

Test(iostr_funs_tests, medium_tests, .init = my_criterion_listener)
{
    my_puterr("Hello ");
    my_dputstr(STDERR_FILENO, "world?");
    cr_assert_stderr_eq_str("Hello world?");

    my_putstr("Hello ");
    my_dputstr(STDOUT_FILENO, "world!");
    cr_assert_stdout_eq_str("Hello world!");
}

Test(file_tokenizer_test, basic_tests, .init = my_criterion_listener)
{
    char **test = my_tokenize_file("../tests/data/file_tokenizer_basic_tests", DEFAULT);

    if (test) {
        for (size_t i = 0; test[i]; i++)
            my_dputstr(STDOUT_FILENO, test[i]);
        my_two_dims_array_destroyer((void **) test);
        cr_assert_stdout_eq_str("Hello world\nNice to meet you\nBake a cake\n");
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(file_tokenizer_test, medium_tests, .init = my_criterion_listener)
{
    node_t *test = (node_t *) my_tokenize_file("../tests/data/file_tokenizer_basic_tests", AS_LIST);
    node_t *cur_node = test;

    cr_assert(!my_tokenize_file("FICHIER INEXISTANT", DEFAULT));
    cr_assert(my_is_empty_list(NULL));

    if (test) {
        cr_assert(my_includes_str(test, "Hello world\n"));
        cr_assert(my_fetch_str_index(test, "Hello world\n") == 0);
        cr_assert(!my_includes_str(test, "NOT IN LINKED LIST\n"));
        cr_assert(my_fetch_str_index(test, "NOT IN LINKED LIST") == -1);
        cr_assert(!my_is_empty_list(test));
        while (cur_node) {
            my_dputstr(STDOUT_FILENO, (char *) cur_node->data);
            cur_node = cur_node->next;
        }
        my_delete_at(&test, 0);
        cr_assert(my_fetch_str_index(test, "Hello world\n") == -1);
        my_linked_list_destroyer(&test);
        cr_assert_stdout_eq_str("Hello world\nNice to meet you\nBake a cake\n");
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(file_tokenizer_test, advanced_tests, .init = my_criterion_listener)
{
    char *test = (char *) my_tokenize_file("../tests/data/file_tokenizer_basic_tests", FLATTEN);

    if (test) {
        my_dputstr(STDOUT_FILENO, test);
        free(test);
        cr_assert_stdout_eq_str("Hello world\nNice to meet you\nBake a cake\n");
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(file_tokenizer_test, random_tests, .init = my_criterion_listener)
{
    char **test = NULL;
    char *f_test = NULL;

    test = my_tokenize_file("../tests/data/file_tokenizer_basic_tests", DEFAULT);
    if (test) {
        f_test = get_flatten_strings_two_dims_arr_rpz(test);
        if (f_test) {
            my_dputstr(STDOUT_FILENO, f_test);
            free(f_test);
            cr_assert_stdout_eq_str("Hello world\nNice to meet you\nBake a cake\n");
        } else
            cr_assert_fail("Failed to malloc\n");
    } else
        cr_assert_fail("Failed to malloc\n");
    my_two_dims_array_destroyer((void **) test);
}

Test(iostr_funs_tests, my_putnbr_test, .init = my_criterion_listener)
{
    my_putnbr(1234);
    my_putnbr_rev(1234);
    my_putnbr(-1234);
    my_putnbr_rev(-1234);
    cr_assert_stdout_eq_str("12344321-1234-4321");
}
