/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** gets a node at a specified position, starting iteration from the head node.
*/

#include <criterion/logging.h>
#include "dllists_obj.h"

node_t *dllist_get_node_from_head(dllist_t *dllist, size_t pos)
{
    node_t *current = NULL;

    if (!dllist ||
        !dllist->head ||
        dllist->len == 0 ||
        pos >= dllist->len)
        return (NULL);
    current = dllist->head;
    for (register size_t i = 0; i <= pos; ++i) {
        if (i == pos)
            return (current);
        current = current->next;
    }
    return (NULL);
}