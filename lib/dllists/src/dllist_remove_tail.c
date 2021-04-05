/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** frees the last node of a dllist_obj, changing pointers accordingly.
*/

#include "dllists_obj.h"
#include <stdlib.h>

static void single_node_dllist_tail_remove(dllist_t *dllist)
{
    free(dllist->tail->data);
    free(dllist->tail);
    dllist->head = NULL;
    dllist->tail = NULL;
}

int dllist_remove_tail(dllist_t *dllist)
{
    node_t *target_prev;

    if (!dllist || dllist->len == 0 || dllist->tail == NULL)
        return (84);
    if (dllist->len == 1) {
        if (dllist->head != dllist->tail)
            return (84);
        else
            single_node_dllist_tail_remove(dllist);
    } else {
        target_prev = dllist->tail->prev;
        free(dllist->tail->data);
        free(dllist->tail);
        target_prev->next = NULL;
        dllist->tail = target_prev;
    }
    dllist->len--;
    return (0);
}