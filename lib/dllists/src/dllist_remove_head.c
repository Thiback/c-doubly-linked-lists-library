/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** frees the first node of a dllist_obj, changing pointers accordingly.
*/

#include "dllists_obj.h"
#include <stdlib.h>

#include "criterion/logging.h"

static void single_node_dllist_head_remove(dllist_t *dllist)
{
    free(dllist->head->data);
    free(dllist->head);
    dllist->head = NULL;
    dllist->tail = NULL;
}

int dllist_remove_head(dllist_t *dllist)
{
    node_t *target_next;

    if (!dllist || dllist->len == 0 || dllist->head == NULL)
        return (84);
    if (dllist->len == 1)
        if (dllist->head != dllist->tail)
            return (84);
        else
            single_node_dllist_head_remove(dllist);
    else {
        target_next = dllist->head->next;
        free(dllist->head->data);
        free(dllist->head);
        target_next->prev = NULL;
        dllist->head = target_next;
    }
    dllist->len--;
    return (0);
}