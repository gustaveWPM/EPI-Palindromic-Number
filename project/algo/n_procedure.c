/*
** EPITECH PROJECT, 2021
** n_procedure.c
** File description:
** Procedure invoked by -n
*/

#include "runtime.h"
#include "runtime_struct.h"

#include "my_itobase.h"
#include "my_string.h"
#include "my_maths_consts.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

static bool reached_last_iteration(palindrome_t *palindrome, int i)
{
    if (i >= palindrome->imin_value && i > palindrome->imax_value)
        return true;
    if (i > MATHS_CONSTS.QUICKFIX_LYCHREL_MAX_ITER)
        return true;
    return false;
}

static bool displayed_palindrome(palindrome_t *pal, int n, int i, int next)
{
    if (i >= pal->imin_value && is_palindrome(next, pal->b_value)) {
        display_palindrome(n, next, i, pal->b_value);
        return true;
    }
    return false;
}

static int get_next_value(palindrome_t *palindrome)
{
    long long next_value = 0;
    char *str = NULL;
    char *rev_str = NULL;
    int rev_value = 0;

    str = my_itobase(palindrome->n_value, palindrome->b_value);
    rev_str = my_create_revstr(str);
    rev_value = my_basetoi(rev_str, palindrome->b_value);
    free(rev_str);
    free(str);
    if (rev_value == -1)
        return -1;
    next_value = rev_value + palindrome->n_value;
    if (next_value > INT_MAX)
        return -1;
    return (int) next_value;
}

bool n_procedure(palindrome_t *palindrome)
{
    int memo_n = palindrome->n_value;
    int next_value = 0;
    int i = 1;
    bool is_pal = false;

    while (true) {
        next_value = get_next_value(palindrome);
        if (next_value < 0)
            break;
        if (displayed_palindrome(palindrome, memo_n, i, next_value)) {
            is_pal = true;
            break;
        }
        palindrome->n_value = next_value;
        i += 1;
        if (reached_last_iteration(palindrome, i)) {
            is_pal = false;
            break;
        }
    }
    return is_pal;
}
