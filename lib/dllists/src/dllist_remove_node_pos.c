/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** removes a node at a specified position from a dllist
*/

#include <stdlib.h>
#include "dllists_obj.h"

static int remove_node(dllist_t *dllist, node_t *target, size_t pos)
{
    node_t *prev;
    node_t *next;

    if (pos == 0)
        return (dllist->remove_head(dllist));
    else if (pos + 1 == dllist->len)
        return (dllist->remove_tail(dllist));
    else {
        prev = target->prev;
        next = target->next;
        free(target->data);
        free(target);
        prev->next = next;
        next->prev = prev;
        dllist->len--;
    }
    return (0);
}

int dllist_remove_node_pos(dllist_t *dllist, size_t pos)
{
    node_t *target;

    if (!dllist || dllist->len <= pos)
        return (84);
    if (pos < dllist->len / 2)
        target = dllist_get_node_from_head(dllist, pos);
    else
        target = dllist_get_node_from_tail(dllist, pos);
    if (target == NULL)
        return (84);
    if (remove_node(dllist, target, pos) != 0)
        return (84);
    return (0);
}