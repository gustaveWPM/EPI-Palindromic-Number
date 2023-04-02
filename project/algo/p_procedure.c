/*
** EPITECH PROJECT, 2021
** p_procedure.c
** File description:
** Procedure invoked by -p
*/

#include "runtime.h"
#include "runtime_struct.h"

#include "my_itobase.h"
#include "my_string.h"
#include "my_maths_consts.h"

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

static bool reached_last_iteration(palindrome_t *palindrome, int i)
{
    if (i >= palindrome->imin_value && i > palindrome->imax_value)
        return true;
    if (i >= MATHS_CONSTS.QUICKFIX_LYCHREL_MAX_ITER)
        return true;
    return false;
}

static int get_next_value(int n, palindrome_t *palindrome)
{
    long long next_value = 0;
    char *j_str = NULL;
    char *j_rev_str = NULL;

    j_str = my_itobase(n, palindrome->b_value);
    j_rev_str = my_create_revstr(j_str);
    next_value = my_basetoi(j_rev_str, palindrome->b_value);
    free(j_str);
    free(j_rev_str);
    if (next_value == -1)
        return -1;
    next_value += n;
    if (next_value > INT_MAX)
        return -1;
    return (int) next_value;
}

static bool p_loop(palindrome_t *palindrome, char *memo_p, int memo_j, int j)
{
    int i = 1;
    char *j_str = NULL;
    int next_value = 0;

    while (true) {
        next_value = get_next_value(j, palindrome);
        if (next_value < 0)
            return false;
        j_str = my_itobase(next_value, palindrome->b_value);
        if (i >= palindrome->imin_value && !my_strcmp(j_str, memo_p)) {
            free(j_str);
            display_palindrome(memo_j, next_value, i, palindrome->b_value);
            return true;
        }
        free(j_str);
        j = next_value;
        i += 1;
        if (reached_last_iteration(palindrome, i))
            break;
    }
    return false;
}

static bool append_last_palindrome(palindrome_t *palindrome)
{
    int p_value = palindrome->p_value;
    uint8_t b_value = palindrome->b_value;

    if (palindrome->imin_value == 0) {
        display_palindrome(p_value, p_value, 0, b_value);
        return true;
    }
    return false;
}

bool p_procedure(palindrome_t *palindrome)
{
    char *memo_p = my_itobase(palindrome->p_value, palindrome->b_value);
    bool is_pal = false;
    int j = compute_j_value(palindrome);

    for (; j <= palindrome->p_value && palindrome->imax_value > 0; j++) {
        if (palindrome->b_value == 10 && is_pal)
            p_bloop(palindrome, j, j);
        if (palindrome->b_value == 10 && !is_pal)
            is_pal = p_bloop(palindrome, j, j);
        if (palindrome->b_value == 10)
            continue;
        if (!is_pal)
            is_pal = p_loop(palindrome, memo_p, j, j);
        else
            p_loop(palindrome, memo_p, j, j);
    }
    free(memo_p);
    if (append_last_palindrome(palindrome))
        return true;
    return is_pal;
}
