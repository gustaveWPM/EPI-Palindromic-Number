/*
** EPITECH PROJECT, 2021
** my_tokenize_file.c
** File description:
** Tokenize a file. Can return a flattened string, a 2d array or a linked list
*/

#include "my_ascii.h"
#include "my_linked_list.h"
#include "my_two_dims_arrays.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void process_tokenize_file(FILE *fp, node_t **tokenized_file)
{
    char *line_buf = NULL;
    size_t data_size = 0;
    size_t line_buf_size = 0;
    ssize_t line_size;

    line_size = my_getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        data_size = (my_strlen(line_buf) + 1) * sizeof(char);
        if (!my_push_head(tokenized_file, (void *) line_buf, data_size)) {
            my_linked_list_destroyer(tokenized_file);
            break;
        }
        line_size = my_getline(&line_buf, &line_buf_size, fp);
    }
    if (line_buf)
        free(line_buf);
    my_revlist(tokenized_file);
    my_shift(tokenized_file);
}

static char *this_flattened_tokenized_file(node_t **list)
{
    node_t *cur_node = *list;
    size_t memsize = 0;
    char *flattened_tokenized_file = NULL;

    while (cur_node) {
        memsize += my_strlen((char *) cur_node->data);
        cur_node = cur_node->next;
    }
    flattened_tokenized_file = malloc((memsize + 1) * sizeof(char));
    if (!flattened_tokenized_file) {
        my_linked_list_destroyer(list);
        return NULL;
    }
    for (size_t i = 0; i <= memsize; i++)
        flattened_tokenized_file[i] = '\0';
    for (cur_node = *list; cur_node; cur_node = cur_node->next)
        my_unsafe_strcat(flattened_tokenized_file, (char *) cur_node->data);
    my_linked_list_destroyer(list);
    return flattened_tokenized_file;
}

char **my_tokenize_file_redirected(enum my_transform_e flag)
{
    char **tokenized_file_arr = NULL;
    node_t *tokenized_file = NULL;

    if (isatty(0))
        return NULL;
    tokenized_file = my_create_linked_list();
    if (!tokenized_file)
        return NULL;
    process_tokenize_file(stdin, &tokenized_file);
    if (flag == FLATTEN)
        return (char **) this_flattened_tokenized_file(&tokenized_file);
    if (flag == AS_LIST)
        return (char **) tokenized_file;
    tokenized_file_arr = str_linked_list_to_two_dims_array(tokenized_file);
    my_linked_list_destroyer(&tokenized_file);
    return tokenized_file_arr;
}

char **my_tokenize_file(char *filepath, enum my_transform_e flag)
{
    char **tokenized_file_arr = NULL;
    FILE *fp = fopen(filepath, "r");
    node_t *tokenized_file = my_create_linked_list();

    if (!fp || !tokenized_file) {
        if (fp)
            fclose(fp);
        if (tokenized_file)
            free(tokenized_file);
        return NULL;
    }
    process_tokenize_file(fp, &tokenized_file);
    fclose(fp);
    if (flag == FLATTEN)
        return (char **) this_flattened_tokenized_file(&tokenized_file);
    if (flag == AS_LIST)
        return (char **) tokenized_file;
    tokenized_file_arr = str_linked_list_to_two_dims_array(tokenized_file);
    my_linked_list_destroyer(&tokenized_file);
    return tokenized_file_arr;
}
