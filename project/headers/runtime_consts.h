/*
** EPITECH PROJECT, 2021
** runtime_consts.h
** File description:
** Runtime consts
*/

#ifndef RUNTIME_CONSTS_H
    #define RUNTIME_CONSTS_H
    static const struct {
        int ERROR_EXIT;
        int NO_VALUE;
        int B_DEFAULT_VALUE;
        int IMIN_DEFAULT_VALUE;
        int IMAX_DEFAULT_VALUE;
        int MIN_BASE;
        int MAX_BASE;
        char *INVALID_ARGUMENT;
        char *NO_SOLUTION;
        char *USAGE;
    } RUNTIME_CONSTS = {
        84,
        -1,
        10,
        0,
        100,
        2,
        10,
        "invalid argument\n",
        "no solution\n",
        "USAGE\n"
        "\t./palindrome -n number -p palindrome [-b base] [-imin i] [-imax i]"
        "\n\nDESCRIPTION\n"
        "\t-n n\t\tinteger to be transformed (>=0)\n"
        "\t-p pal\t\tpalindromic number to be obtained (incompatible with the "
        "-n option) (>= 0)\n"
        "\t\t\tif defined, all fitting values of n will be output\n"
        "\t-b base\t\tbase in which the procedure will be executed (1<b<=10) "
        "[def: 10]\n"
        "\t-imin i\t\tminimum number of iterations, included (>= 0) [def: 0]\n"
        "\t-imax i\t\tmaximum number of iterations, included (>= 0) "
        "[def: 100]\n"
    };
#endif
