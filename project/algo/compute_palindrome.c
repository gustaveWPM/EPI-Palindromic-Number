/*
** EPITECH PROJECT, 2021
** compute_palindrome.c
** File description:
** Palindrome algorithm entry point
*/

#include "runtime.h"
#include "runtime_struct.h"
#include "runtime_consts.h"

#include <stdio.h>

static bool already_palindrome(palindrome_t *palindrome)
{
    int n_value = palindrome->n_value;
    uint8_t b_value = palindrome->b_value;

    if (palindrome->imin_value != 0)
        return false;
    if (is_palindrome(n_value, b_value)) {
        display_palindrome(n_value, n_value, 0, b_value);
        return true;
    }
    if (palindrome->imax_value == 0) {
        no_solution_msg();
        return true;
    }
    return false;
}

int compute_palindrome(palindrome_t *palindrome)
{
    if (palindrome->n_value != RUNTIME_CONSTS.NO_VALUE) {
        if (already_palindrome(palindrome))
            return 0;
        if (!n_procedure(palindrome))
            no_solution_msg();
        return 0;
    }
    if (palindrome->p_value != RUNTIME_CONSTS.NO_VALUE) {
        if (!is_palindrome(palindrome->p_value, palindrome->b_value))
            return RUNTIME_CONSTS.ERROR_EXIT;
        if (!p_procedure(palindrome))
            no_solution_msg();
        return 0;
    }
    return 0;
}
