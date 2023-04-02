/*
** EPITECH PROJECT, 2021
** run.c
** File description:
** Runtime
*/

#include "runtime_struct.h"
#include "runtime_consts.h"
#include "runtime.h"

#include "my_string.h"
#include "my_optflags.h"

int run(optflags_t *opt, palindrome_t *palindrome)
{
    int inject_values_ret = inject_values(opt, palindrome);
    int compute_palindrome_ret = 0;

    if (inject_values_ret != 0) {
        terminate(opt);
        return inject_values_ret;
    }
    if (palindrome->imin_value > palindrome->imax_value) {
        terminate(opt);
        return RUNTIME_CONSTS.ERROR_EXIT;
    }
    my_optflags_destroy(&opt);
    compute_palindrome_ret = compute_palindrome(palindrome);
    if (compute_palindrome_ret)
        return compute_palindrome_ret;
    return 0;
}
