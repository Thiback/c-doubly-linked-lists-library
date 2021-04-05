/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** inserts the specified data at the specified position of a dllist
*/

#include <stdlib.h>
#include "dllists_obj.h"

static int _dllist_insert_from_head(dllist_t *dllist, void *data, size_t pos)
{
    node_t *prev = NULL;
    node_t *current = NULL;

    prev = dllist_get_node_from_head(dllist, pos - 1);
    if (!(current = malloc(sizeof(node_t))))
        return (84);
    current->next = prev->next;
    prev->next = current;
    if (current->next)
        current->next->prev = current;
    current->data = data;
    dllist->len++;
    return (0);
}

static int _dllist_insert_from_tail(dllist_t *dllist, void *data, size_t pos)
{
    node_t *prev = NULL;
    node_t *new = NULL;
    node_t *next =  dllist_get_node_from_tail(dllist, pos);

    if (!(new = malloc(sizeof(node_t))))
        return (84);
    prev = next->prev;
    new->prev = prev;
    next->prev = new;
    new->next = next;
    prev->next = new;
    new->data = data;
    dllist->len++;
    return (0);
}

static int _dllist_insert(dllist_t *dllist, void *data, size_t pos)
{
    if (dllist->len / 2 > pos)
        return (_dllist_insert_from_head(dllist, data, pos));
    else
        return (_dllist_insert_from_tail(dllist, data, pos));
    return (84);
}

int dllist_insert_data(dllist_t *dllist, void *data, size_t pos)
{
    if (!dllist || dllist->len < pos ||
        (dllist->len && (!dllist->tail || !dllist->head)))
        return (84);
    if (pos == 0)
        return (dllist->add_head(dllist, data));
    else if (pos == dllist->len)
        return (dllist->add_tail(dllist, data));
    else
        return (_dllist_insert(dllist, data, pos));
    return (84);
}