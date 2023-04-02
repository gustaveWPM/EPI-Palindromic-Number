/*
** EPITECH PROJECT, 2021
** ascii_consts.h
** File description:
** ASCII Consts
*/

#ifndef ASCII_MACROS_H
    #define ASCII_MACROS_H
    #include <stdint.h>

    static const struct {
        uint8_t DOWNCASE_ASCII_DELTA;
        uint8_t CTOI_DELTA;
    } ASCII_CONSTS = {
        32,
        48
    };
#endif
