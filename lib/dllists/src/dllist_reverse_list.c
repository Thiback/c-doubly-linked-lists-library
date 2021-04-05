/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** reverse the order of the nodes of the specified dllist.
*/

#include "dllists_obj.h"

int dllist_reverse_list(dllist_t *dllist)
{
    node_t *current_a = NULL;
    node_t *current_b = NULL;
    void *tmp = NULL;

    if (dllist == NULL || dllist->len == 0)
        return (84);
    if (dllist->len == 1)
        return (0);
    current_a = dllist->head;
    current_b = dllist->tail;
    for (register int i = dllist->len / 2; i > 0; --i) {
        tmp = current_a->data;
        current_a->data = current_b->data;
        current_b->data = tmp;
        current_a = current_a->next;
        current_b = current_b->prev;
    }
    return (0);
}