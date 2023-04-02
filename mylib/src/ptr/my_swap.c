/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** Swap two pointers, or two data structures
*/

#include <stddef.h>
#include <stdint.h>

void my_swap_ptr(void *ptr_a, void *ptr_b)
{
    int8_t temp = *(int8_t *) ptr_a;

    *(int8_t *) ptr_a = *(int8_t *) ptr_b;
    *(int8_t *) ptr_b = temp;
}

void my_swap_data(void *ptr_a, void *ptr_b, size_t data_size)
{
    unsigned char *data_a = ptr_a;
    unsigned char *data_b = ptr_b;
    unsigned char tmp = 0;

    for (size_t i = 0; i != data_size; i++) {
        tmp = data_a[i];
        data_a[i] = data_b[i];
        data_b[i] = tmp;
    }
}
