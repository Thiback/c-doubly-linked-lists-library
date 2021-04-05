/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** returns a new dllist with null values and initialized function pointers.
*/

#include "dllists_obj.h"

dllist_t dllist_create()
{
    dllist_t new_list;

    new_list.head = NULL;
    new_list.tail = NULL;
    new_list.len = 0;
    new_list.add_head = dllist_add_head;
    new_list.insert = dllist_insert_data;
    new_list.add_tail = dllist_add_tail;
    new_list.listlen = dllist_listlen;
    new_list.remove_head = dllist_remove_head;
    new_list.remove_tail = dllist_remove_tail;
    new_list.remove_pos = dllist_remove_node_pos;
    new_list.at = dllist_get_data_at;
    new_list.delete = dllist_free_list;
    new_list.swap = dllist_swap_data;
    new_list.to_ptr_array = dllist_to_ptr_array;
    new_list.reverse = dllist_reverse_list;
    new_list.callback = dllist_iterate_with_callback;
    return (new_list);
}