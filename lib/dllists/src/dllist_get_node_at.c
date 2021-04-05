/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** gets a node from a dllist at a specified position.
*/

#include "dllists_obj.h"

node_t *dllist_get_node_at(dllist_t *dllist, size_t pos)
{
    if (!dllist)
        return (NULL);
    if (pos <= dllist->len / 2)
        return (dllist_get_node_from_head(dllist, pos));
    else
        return (dllist_get_node_from_tail(dllist, pos));
    return (NULL);
}