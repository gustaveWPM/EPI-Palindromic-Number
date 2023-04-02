/*
** EPITECH PROJECT, 2021
** my_math_parity.h
** File description:
** Math parity macros
*/

#ifndef MY_MATH_PARITY_H
    #define MY_MATH_PARITY_H
    #include <stdbool.h>
    #include <stdint.h>

    #define MY_ISEVEN(number) (number % 2 == 0)
    #define MY_ISODD(number) (number % 2 == 1 || number % 2 == -1)
    #define MY_ISODD_U(number) (number % 2 == 1)
#endif
