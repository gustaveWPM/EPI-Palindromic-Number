/*
** EPITECH PROJECT, 2021
** my_iostring.h
** File description:
** IO Str funs prototypes
*/

#ifndef TOKENIZE_FILE_FLAGS_H
    #define TOKENIZE_FILE_FLAGS_H
    enum my_transform_e {
        FLATTEN,
        AS_LIST,
        DEFAULT
    };
#endif

#ifndef MY_IOSTRING_H
    #define MY_IOSTRING_H
    #include "my_linked_list.h"
    #include <stdint.h>
    #include <stdio.h>
    #include <stddef.h>

    void my_putstr(char *str);
    void my_puterr(char *str);
    void my_dputstr(uint8_t fileno, char *str);

    void my_putnbr(long long nbr);
    void my_putnbr_rev(long long nbr);
    void my_dputnbr(uint8_t fileno, char *str);
    void my_dputnbr_rev(uint8_t fileno, char *str);

    ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
    char **my_tokenize_file(char *filepath, enum my_transform_e flag);
    char **my_tokenize_file_redirected(enum my_transform_e flag);
#endif
