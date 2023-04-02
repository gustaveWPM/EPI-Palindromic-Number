/*
** EPITECH PROJECT, 2021
** inject_values_internals.c
** File description:
** imin and imax values injections (2nd file to respect Epitech standards)
*/

#include "my_optflags.h"
#include "runtime_struct.h"
#include "my_string.h"
#include "my_strtypes.h"

#include <limits.h>
#include <stdbool.h>

bool inject_imin_value(optflags_t *opt, palindrome_t *palindrome)
{
    long long imin_value = 0;

    if (!my_includes_flag(opt, "-imin"))
        return true;
    if (my_includes_flag(opt, "-imin")) {
        imin_value = my_atol(my_fetch_first_flag_value(opt, "-imin"));
        if (imin_value > INT_MAX || imin_value < 0)
            return false;
        palindrome->imin_value = (int) imin_value;
        return my_isdigit(my_fetch_first_flag_value(opt, "-imin"));
    }
    return true;
}

bool inject_imax_value(optflags_t *opt, palindrome_t *palindrome)
{
    long long imax_value = 0;

    if (my_includes_flag(opt, "-imax")) {
        imax_value = my_atol(my_fetch_first_flag_value(opt, "-imax"));
        if (imax_value > INT_MAX || imax_value < 0)
            return false;
        palindrome->imax_value = (int) imax_value;
        return my_isdigit(my_fetch_first_flag_value(opt, "-imax"));
    }
    return true;
}
