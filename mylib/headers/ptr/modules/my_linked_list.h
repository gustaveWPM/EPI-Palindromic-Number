/*
** EPITECH PROJECT, 2021
** my_linked_list.h
** File description:
** Generic linked list
*/

#ifndef MY_LINKED_LIST_STRUCT_H
    #define MY_LINKED_LIST_STRUCT_H
    typedef struct node_s {
        void *data;
        struct node_s *next;
    } node_t;
#endif

#ifndef MY_LINKED_LIST_FUNS_PROTOTYPES_H
    #define MY_LINKED_LIST_FUNS_PROTOTYPES_H
    #include <stdbool.h>
    #include <stddef.h>
    bool my_push_at(node_t **list, void *new_d, size_t d_size, size_t index);
    bool my_push_head(node_t **list, void *new_data, size_t data_size);
    bool my_push_back(node_t **list, void *new_data, size_t data_size);

    void my_revlist(node_t **list);
    bool my_shift(node_t **list);
    bool my_pop(node_t **list);

    node_t *my_create_linked_list(void);
    bool my_linked_list_destroyer(node_t **list);
    size_t my_linked_list_len(node_t *list);

    long long my_fetch_nb_index(node_t *list, long long nb_lld);
    long long my_fetch_str_index(node_t *list, char *str);

    bool my_includes_nb(node_t *list, long long nb_lld);
    bool my_includes_str(node_t *list, char *str);
    bool my_is_empty_list(node_t *list);

    bool my_delete_at(node_t **list, size_t index);

    bool my_delete_all_nb(node_t **list, long long nb_lld);
    bool my_delete_first_nb(node_t **list, long long nb_lld);

    bool my_delete_all_str(node_t **list, char *str);
    bool my_delete_first_str(node_t **list, char *str);

    node_t *my_fetchall_str_index(node_t *list, char *str);
    node_t *my_fetchall_nb_index(node_t *list, long long nb_lld);

    long long my_count_str(node_t *list, char *str);
    long long my_count_nb(node_t *list, long long nb_lld);

    char **str_linked_list_to_two_dims_array(node_t *list);
#endif
