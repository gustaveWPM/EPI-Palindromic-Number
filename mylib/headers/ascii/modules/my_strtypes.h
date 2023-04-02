/*
** EPITECH PROJECT, 2021
** my_strtypes.h
** File description:
** Str types funs prototypes
*/

#ifndef MY_STRTYPES_H
    #define MY_STRTYPES_H
    #include <stdbool.h>

    bool my_isdigit(char *str);
    bool my_isalpha(char *str);
    bool my_islower(char *str);
    bool my_isupper(char *str);
    bool my_isalphanum(char *str);
    bool my_is_printable(char *str);

    bool str_all(char *str, bool fun_ptr (char c));
    bool str_any(char *str, bool fun_ptr (char c));
    bool str_none(char *str, bool fun_ptr (char c));
#endif
