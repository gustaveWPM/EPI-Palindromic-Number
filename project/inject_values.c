/*
** EPITECH PROJECT, 2021
** inject_values.c
** File description:
** Inject values functions
*/

#include "runtime_struct.h"
#include "runtime_consts.h"
#include "runtime.h"
#include "inject_values_internals.h"

#include "my_optflags.h"
#include "my_string.h"
#include "my_strtypes.h"

#include <stdbool.h>
#include <limits.h>

static bool inject_p_value(optflags_t *opt, palindrome_t *palindrome)
{
    long long p_value = RUNTIME_CONSTS.NO_VALUE;

    if (my_includes_flag(opt, "-p")) {
        if (!my_isdigit(my_fetch_first_flag_value(opt, "-p")))
            return false;
        p_value = my_atol(my_fetch_first_flag_value(opt, "-p"));
        if (p_value > INT_MAX || p_value < 0)
            return false;
    }
    palindrome->p_value = p_value;
    return true;
}

static bool inject_n_value(optflags_t *opt, palindrome_t *palindrome)
{
    long long n_value = RUNTIME_CONSTS.NO_VALUE;

    if (my_includes_flag(opt, "-n")) {
        if (!my_isdigit(my_fetch_first_flag_value(opt, "-n")))
            return false;
        n_value = my_atol(my_fetch_first_flag_value(opt, "-n"));
        if (n_value > INT_MAX || n_value < 0)
            return false;
    }
    palindrome->n_value = n_value;
    return true;
}

static bool inject_b_value(optflags_t *opt, palindrome_t *palindrome)
{
    long long b_value = 0;

    if (!my_includes_flag(opt, "-b"))
        return true;
    if (!my_isdigit(my_fetch_first_flag_value(opt, "-b")))
        return false;
    b_value = my_atol(my_fetch_first_flag_value(opt, "-b"));
    if (b_value > RUNTIME_CONSTS.MAX_BASE || b_value < RUNTIME_CONSTS.MIN_BASE)
        return false;
    palindrome->b_value = (int) b_value;
    return true;
}

int inject_values(optflags_t *opt, palindrome_t *palindrome)
{
    if (!my_includes_flag(opt, "-n") && !my_includes_flag(opt, "-p"))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (one_more_error_handling(opt))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (!inject_n_value(opt, palindrome))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (!inject_p_value(opt, palindrome))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (!inject_b_value(opt, palindrome))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (!inject_imin_value(opt, palindrome))
        return RUNTIME_CONSTS.ERROR_EXIT;
    if (!inject_imax_value(opt, palindrome))
        return RUNTIME_CONSTS.ERROR_EXIT;
    return 0;
}
