/*
** EPITECH PROJECT, 2021
** entry_point.c
** File description:
** Entry point
*/

#include "runtime_struct.h"
#include "runtime_consts.h"
#include "runtime.h"

#include "my_optflags.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

static int8_t usage(optflags_t *opt, int argc)
{
    if (my_includes_flag(opt, "-h")) {
        if (argc == 2) {
            usage_msg();
            return 0;
        }
        invalid_arg_msg();
        return RUNTIME_CONSTS.ERROR_EXIT;
    }
    return -1;
}

static palindrome_t initialize_palindrome_data(void)
{
    palindrome_t palindrome = {
        .n_value = RUNTIME_CONSTS.NO_VALUE,
        .p_value = RUNTIME_CONSTS.NO_VALUE,
        .b_value = RUNTIME_CONSTS.B_DEFAULT_VALUE,
        .imax_value = RUNTIME_CONSTS.IMAX_DEFAULT_VALUE,
        .imin_value = RUNTIME_CONSTS.IMIN_DEFAULT_VALUE
    };

    return palindrome;
}

static int no_arg_error(void)
{
    invalid_arg_msg();
    return RUNTIME_CONSTS.ERROR_EXIT;
}

int entry_point(int argc, char **argv)
{
    optflags_t *opt = NULL;
    palindrome_t palindrome = initialize_palindrome_data();
    int8_t usage_ret = 0;

    if (argc < 2)
        return no_arg_error();
    opt = my_optflags_builder(argc, argv, true, false);
    if (!opt) {
        invalid_arg_msg();
        return RUNTIME_CONSTS.ERROR_EXIT;
    }
    usage_ret = usage(opt, argc);
    if (usage_ret != -1) {
        terminate(opt);
        return usage_ret;
    }
    if (run(opt, &palindrome) == RUNTIME_CONSTS.ERROR_EXIT) {
        invalid_arg_msg();
        return RUNTIME_CONSTS.ERROR_EXIT;
    }
    return 0;
}
