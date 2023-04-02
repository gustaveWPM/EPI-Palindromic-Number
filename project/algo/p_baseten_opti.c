/*
** EPITECH PROJECT, 2021
** p_bprocedure.c
** File description:
** -p loop (Base 10 optimization)
*/

#include "runtime.h"
#include "runtime_struct.h"
#include "my_maths.h"
#include "my_maths_consts.h"
#include "my_string.h"

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

static bool reached_last_iteration(palindrome_t *palindrome, int i)
{
    if (i >= palindrome->imin_value && i > palindrome->imax_value)
        return true;
    if (i > MATHS_CONSTS.QUICKFIX_LYCHREL_MAX_ITER)
        return true;
    return false;
}

bool p_bloop(palindrome_t *palindrome, int memo_j, int j)
{
    int i = 1;
    long long next_v = 0;
    int p = palindrome->p_value;

    while (true) {
        next_v = my_revint(j) + j;
        if (next_v < 0 || next_v > INT_MAX)
            return false;
        if (i >= palindrome->imin_value && p == next_v) {
            display_palindrome(memo_j, next_v, i, palindrome->b_value);
            return true;
        }
        j = next_v;
        i += 1;
        if (reached_last_iteration(palindrome, i))
            break;
    }
    return false;
}

int compute_j_value(palindrome_t *palindrome)
{
    int j = 0;
    char *rpz = NULL;
    size_t str_len = 0;

    if (palindrome->b_value != 10)
        return j;
    rpz = my_itobase(palindrome->p_value, 10);
    if (!rpz)
        return j;
    if (rpz[0] == '1' && my_strchars(rpz, "01")) {
        str_len = my_strlen(rpz);
        if (rpz[str_len - 1] == '1') {
            free(rpz);
            return palindrome->p_value - 1;
        }
    }
    if (rpz)
        free(rpz);
    return j;
}
