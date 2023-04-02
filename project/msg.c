/*
** EPITECH PROJECT, 2021
** msg.c
** File description:
** Messages
*/

#include "runtime_consts.h"

#include <stdio.h>
#include <stdint.h>

void display_palindrome(int n, int res, int i, uint8_t base)
{
    dprintf(
        1, "%d leads to %d in %d iteration(s) in base %d\n", n, res, i, base
    );
}

void invalid_arg_msg(void)
{
    dprintf(2, "%s", RUNTIME_CONSTS.INVALID_ARGUMENT);
}

void usage_msg(void)
{
    dprintf(1, "%s", RUNTIME_CONSTS.USAGE);
}

void no_solution_msg(void)
{
    dprintf(1, "%s", RUNTIME_CONSTS.NO_SOLUTION);
}
