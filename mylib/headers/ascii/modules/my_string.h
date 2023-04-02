/*
** EPITECH PROJECT, 2021
** my_string.h
** File description:
** Str funs prototypes
*/

#ifndef MY_STRING_H
    #define MY_STRING_H
    #include <stddef.h>
    #include <stdint.h>
    #include <stdbool.h>

    bool my_is_empty_str(char *str);

    size_t my_strlen(char *str);
    int my_strcmp(const char *str_a, const char *str_b);

    void my_str_capitalize(char *str);
    void my_str_capitalize_each_word(char *str);

    char *my_str_sanitize(char *str, char *forbidden_chars);
    char *my_create_empty_string(void);

    void my_str_downcase(char *str);
    void my_str_uppercase(char *str);
    void my_str_togglecase(char *str);

    bool my_strcpy(char *str_from, char *str_to);
    void my_unsafe_strcpy(char *str_from, char *str_to);

    void my_revstr(char *str);
    char *my_create_revstr(char *str);

    char *my_strdup(char *str);
    char *my_strndup(char *str, size_t n);

    char *my_strcat(char *dest, char *src);
    void my_unsafe_strcat(char *dest, char *src);

    int64_t my_atol(char *str);
    bool str_alphabetical_order_cmp(char *str_a, char *str_b);
    char **my_strsplit(char *str, char *separators, char *forbidden_chars);

    bool my_tr(char *str, char *set_a, char *set_b);
    char *my_create_tr(char *str, char *set_a, char *set_b);

    bool my_strchars(char *str, char *authorized_chars);
#endif
