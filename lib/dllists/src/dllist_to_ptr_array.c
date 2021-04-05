/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** returns the list's contents in a pointer array form.
*/

#include <stdlib.h>
#include "dllists_obj.h"

#include <criterion/logging.h>

void **dllist_to_ptr_array(dllist_t *dllist)
{
    void **ptr_array = NULL;
    node_t *current;

    if (!dllist || dllist->len == 0)
        return (NULL);
    ptr_array = malloc(sizeof(void *) * dllist->len);
    if (!ptr_array)
        return (NULL);
    current = dllist->head;
    for (register size_t i = 0; current; current = current->next)
        ptr_array[i++] = current->data;
    return (ptr_array);
}