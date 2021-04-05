/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** header of the library
*/

#ifndef DLLIST_OBJ_LIB
#define DLLIST_OBJ_LIB

#include <stddef.h>

typedef struct node_s {
    struct node_s *prev;
    struct node_s *next;
    void *data;
} node_t;

typedef struct dllist_s {
    node_t *head;
    node_t *tail;
    size_t len;
    int (*add_head)(struct dllist_s *list, void *data);
    int (*insert)(struct dllist_s * dllist, void *data, size_t pos);
    int (*add_tail)(struct dllist_s *list, void *data);
    size_t (*listlen)(struct dllist_s *list);
    void *(*at)(struct dllist_s *dllist, size_t pos);
    int (*swap)(struct dllist_s *dllist, size_t pos_a, size_t pos_b);
    int (*reverse)(struct dllist_s *dllist);
    int (*callback)(struct dllist_s *dllist, void *(_callback)(void *));
    int (*remove_head)(struct dllist_s *dllist);
    int (*remove_pos)(struct dllist_s *dllist, size_t pos);
    int (*remove_tail)(struct dllist_s *dllist);
    void (*delete)(struct dllist_s *dllist);
    void **(*to_ptr_array)(struct dllist_s *dllist);
} dllist_t;

dllist_t dllist_create();
int dllist_add_head(dllist_t *list, void *data);
int dllist_insert_data(dllist_t *dllist, void *data, size_t pos);
int dllist_add_tail(dllist_t *list, void *data);
size_t dllist_listlen(dllist_t *dllist);
int dllist_remove_tail(dllist_t *dllist);
int dllist_remove_head(dllist_t *dllist);
int dllist_remove_node_pos(dllist_t *dllist, size_t pos);
node_t *dllist_get_node_from_head(dllist_t *dllist, size_t pos);
node_t *dllist_get_node_from_tail(dllist_t *dllist, size_t pos);
node_t *dllist_get_node_at(dllist_t *dllist, size_t pos);
void *dllist_get_data_at(dllist_t *dllist, size_t pos);
int dllist_swap_data(dllist_t *dllist, size_t posa, size_t posb);
void dllist_free_list(dllist_t *dllist);
void **dllist_to_ptr_array(dllist_t *dllist);
void *dllist_callback(dllist_t *dllist, void *(*_callback)(void *));
int dllist_reverse_list(dllist_t *dllist);
dllist_t *array_to_dllist(void **array, size_t array_size);
int dllist_iterate_with_callback(dllist_t *dllist, void *(_callback)(void *));

#endif /*DLLIST_OBJ_LIB*/
