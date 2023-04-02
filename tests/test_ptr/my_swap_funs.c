/*
** EPITECH PROJECT, 2021
** my_swap_funs.c
** File description:
** My swap funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_ptr.h"
#include <stdlib.h>

void my_criterion_listener(void);

Test(ptr_funs_test, test_swap_data, .init = NULL)
{
    int twenty = 10;
    int ten = 20;

    my_swap_data(&twenty, &ten, sizeof(int));
    cr_assert(twenty == 20);
    cr_assert(ten == 10);
}

Test(ptr_funs_test, test_swap_ptr, .init = NULL)
{
    char a = 'a';
    char b = 'b';
    int ten = 10;
    int twenty = 20;

    my_swap_ptr((void *) &a, (void *) &b);
    cr_assert(a == 'b');
    cr_assert(b == 'a');

    my_swap_ptr((void *) &ten, (void *) &twenty);
    cr_assert(ten == 20);
    cr_assert(twenty == 10);
}
