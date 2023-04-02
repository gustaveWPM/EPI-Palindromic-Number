/*
** EPITECH PROJECT, 2021
** my_itobase.h
** File description:
** My itobase (and vice-versa) functions prototypes
*/

#ifndef MY_ITOBASE_H
    #define MY_ITOBASE_H
    #include <stdint.h>
    int my_basetoi(char *number, int8_t base);
    char *my_itobase(unsigned int value, uint8_t base);
#endif