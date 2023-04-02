/*
** EPITECH PROJECT, 2021
** my_linked_lists_funs.c
** File description:
** My linked lists funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_linked_list.h"
#include "my_linked_lists_debug.h"
#include "my_string.h"

#include <unistd.h>

void my_criterion_listener(void);

Test(linked_lists_test, int_tests, .init = my_criterion_listener)
{
    node_t *list = NULL;
    int collection[] = {10, 20, 30, 40, 50, -1};

    for (size_t i = 0; collection[i] != -1; i++) {
        if (!my_push_head(&list, &collection[i], sizeof(int))) {
            my_linked_list_destroyer(&list);
            cr_assert_fail("Failed to malloc\n");
        }
    }
    my_revlist(&list);
    print_list(list, print_int);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("10 20 30 40 50 ");
}

Test(linked_lists_test, float_tests, .init = my_criterion_listener)
{
    node_t *list = NULL;
    float collection[] = {10.1, 20.2, 30.3, 40.4, 50.5, -1};

    for (size_t i = 0; collection[i] != -1; i++) {
        if (!my_push_head(&list, &collection[i], sizeof(float))) {
            my_linked_list_destroyer(&list);
            cr_assert_fail("Failed to malloc\n");
        }
    }
    print_list(list, print_float);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("50.5 40.4 30.3 20.2 10.1 ");
}

Test(linked_lists_test, int_tests_pushback, .init = my_criterion_listener)
{
    node_t *list = NULL;
    int collection[] = {10, 20, 30, 40, 50, -1};

    for (size_t i = 0; collection[i] != -1; i++) {
        if (!my_push_back(&list, &collection[i], sizeof(int))) {
            my_linked_list_destroyer(&list);
            cr_assert_fail("Failed to malloc\n");
        }
    }
    print_list(list, print_int);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("10 20 30 40 50 ");
}

Test(linked_lists_test, basic_tests, .init = my_criterion_listener)
{
    node_t *list = NULL;
    int data = 12;

    cr_assert(!my_shift(&list));
    cr_assert(!my_pop(&list));
    cr_assert(!my_linked_list_destroyer(&list));
    my_push_back(&list, &data, sizeof(int));
    my_push_back(&list, &data, sizeof(int));
    my_pop(&list);
    print_list(list, print_int);
    my_pop(&list);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("12 ");
}

Test(linked_lists_test, push_at_tests, .init = my_criterion_listener)
{
    node_t *list = NULL;
    int data = 12;

    my_push_at(&list, &data, sizeof(int), 0);
    my_push_at(&list, &data, sizeof(int), 3);
    print_list(list, print_int);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("12 12 ");
}

Test(linked_lists_test, medium_tests, .init = NULL)
{
    node_t *list = NULL;
    int test = 4;

    cr_assert(!my_delete_at(&list, 1));
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 16;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 24;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");

    test = 24;
    cr_assert(my_fetch_nb_index(list, test) == 0);
    cr_assert(my_includes_nb(list, test));
    test = 16;
    cr_assert(my_fetch_nb_index(list, test) == 1);
    cr_assert(my_includes_nb(list, test));
    test = 8;
    cr_assert(my_fetch_nb_index(list, test) == 2);
    cr_assert(my_includes_nb(list, test));
    test = 4;
    cr_assert(my_fetch_nb_index(list, test) == 3);
    cr_assert(my_includes_nb(list, test));
    test = 8923;
    cr_assert(my_fetch_nb_index(list, test) == -1);
    cr_assert(!my_includes_nb(list, test));
    cr_assert(!my_delete_at(&list, 12831));
    my_linked_list_destroyer(&list);
}

Test(linked_lists_test, advanced_tests, .init = NULL)
{
    node_t *list = NULL;
    int test = 4;

    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    my_delete_all_nb(&list, 4);
    cr_assert(!my_delete_all_nb(&list, 21324));
    cr_assert(my_fetch_nb_index(list, 4) == -1);
    my_linked_list_destroyer(&list);
}

Test(linked_lists_test, another_test, .init = NULL)
{
    node_t *list = NULL;
    int test = 4;

    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    my_delete_first_nb(&list, 4);
    cr_assert(!my_delete_first_nb(&list, 2132183));
    cr_assert(my_fetch_nb_index(list, 4) == 2);
    my_linked_list_destroyer(&list);
}

Test(linked_lists_test, fetchall_nb_test, .init = my_criterion_listener)
{
    node_t *list = NULL;
    node_t *fetchall_test = NULL;
    int test = 4;

    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    my_delete_first_nb(&list, 4);
    fetchall_test = my_fetchall_nb_index(list, 8);
    cr_assert(my_count_nb(list, 8) == 2);
    print_list(fetchall_test, print_int);
    cr_assert_stdout_eq_str("0 1 ");
    my_linked_list_destroyer(&list);
    my_linked_list_destroyer(&fetchall_test);
}

Test(linked_lists_test, fetchall_str_test, .init = my_criterion_listener)
{
    node_t *list = NULL;
    node_t *fetchall_test = NULL;
    char *str_buf = NULL;
    size_t data_size = 0;

    str_buf = "Hello";
    data_size = (my_strlen(str_buf) + 1) * sizeof(char);
    if (!my_push_head(&list, (void *) str_buf, data_size))
        cr_assert_fail("Failed to malloc\n");

    str_buf = "Hello";
    data_size = (my_strlen(str_buf) + 1) * sizeof(char);
    if (!my_push_head(&list, (void *) str_buf, data_size))
        cr_assert_fail("Failed to malloc\n");

    str_buf = "World";
    data_size = (my_strlen(str_buf) + 1) * sizeof(char);
    if (!my_push_head(&list, (void *) str_buf, data_size))
        cr_assert_fail("Failed to malloc\n");
    str_buf = "Bake a cake";
    data_size = (my_strlen(str_buf) + 1) * sizeof(char);
    if (!my_push_head(&list, (void *) str_buf, data_size))
        cr_assert_fail("Failed to malloc\n");

    my_revlist(&list);
    cr_assert(my_count_str(list, "Hello") == 2);

    cr_assert(my_includes_str(list, "Hello"));
    fetchall_test = my_fetchall_str_index(list, "Hello");
    print_list(fetchall_test, print_int);

    my_delete_first_str(&list, "Hello");

    cr_assert(!my_delete_first_str(&list, "NOT IN LINKED LIST"));
    cr_assert(!my_delete_all_str(&list, "NOT IN LINKED LIST"));

    my_linked_list_destroyer(&fetchall_test);
    fetchall_test = my_fetchall_str_index(list, "Hello");
    print_list(fetchall_test, print_int);

    my_delete_all_str(&list, "Hello");

    my_linked_list_destroyer(&fetchall_test);
    fetchall_test = my_fetchall_str_index(list, "Hello");
    print_list(fetchall_test, print_int);

    my_linked_list_destroyer(&list);
    my_linked_list_destroyer(&fetchall_test);
    cr_assert_stdout_eq_str("0 1 0 ");
}

Test(linked_lists_test, push_at_test, .init = my_criterion_listener)
{
    node_t *list = NULL;
    int test = 0;

    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 4;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 8;
    if (!my_push_head(&list, (void *) &test, sizeof(int)))
        cr_assert_fail("Failed to malloc\n");
    test = 3;
    my_push_at(&list, (void *) &test, sizeof(int), 3);
    test = 12;
    my_push_at(&list, (void *) &test, sizeof(int), 9);
    test = 1;
    my_push_at(&list, (void *) &test, sizeof(int), 0);
    print_list(list, print_int);
    my_linked_list_destroyer(&list);
    cr_assert_stdout_eq_str("1 8 4 8 3 4 12 ");
}
