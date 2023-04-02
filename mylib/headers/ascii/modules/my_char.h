/*
** EPITECH PROJECT, 2021
** my_char.h
** File description:
** Char funs prototypes
*/

#ifndef MY_CHAR_H
    #define MY_CHAR_H
    #include <stdbool.h>

    void my_char_upcase(char *c);
    void my_char_downcase(char *c);
    void my_char_togglecase(char *c);

    bool my_is_alphachar(char c);
    bool my_is_digitchar(char c);
    bool my_is_lowerchar(char c);
    bool my_is_upperchar(char c);
    bool my_is_printablechar(char c);
    bool my_is_alphanum_char(char c);

    bool my_char_in_str(char c, char *str);
#endif
