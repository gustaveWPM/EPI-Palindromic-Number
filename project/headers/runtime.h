/*
** EPITECH PROJECT, 2021
** runtime.h
** File description:
** Runtime header file
*/

#ifndef RUNTIME_PROTOTYPES_H
    #define RUNTIME_PROTOTYPES_H
    #include "my_optflags.h"
    #include "runtime_struct.h"
    #include <stdint.h>
    #include <stdbool.h>

    int run(optflags_t *opt, palindrome_t *palindrome);
    void terminate(optflags_t *opt);

    bool is_palindrome(int nb, uint8_t base);

    int inject_values(optflags_t *opt, palindrome_t *palindrome);
    int compute_palindrome(palindrome_t *palindrome);

    bool n_procedure(palindrome_t *palindrome);
    bool p_procedure(palindrome_t *palindrome);

    bool is_lychrel(int i);
    bool p_bloop(palindrome_t *palindrome, int memo_j, int j);
    int compute_j_value(palindrome_t *palindrome);
    bool one_more_error_handling(optflags_t *opt);

    void display_palindrome(int n, int res, int i, uint8_t base);
    void invalid_arg_msg(void);
    void usage_msg(void);
    void no_solution_msg(void);
#endif
