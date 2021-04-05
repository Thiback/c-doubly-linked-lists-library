/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** gets a node at a specified position, starting iteration from the tail node.
*/

#include "dllists_obj.h"

node_t *dllist_get_node_from_tail(dllist_t *dllist, size_t pos)
{
    node_t *current = NULL;

    if (!dllist ||
        !dllist->tail ||
        dllist->len == 0 ||
        pos > dllist->len - 1)
        return (NULL);
    current = dllist->tail;
    for (register size_t i = dllist->len - 1; i >= pos; --i) {
        if (i == pos)
            return (current);
        current = current->prev;
    }
    return (NULL);
}