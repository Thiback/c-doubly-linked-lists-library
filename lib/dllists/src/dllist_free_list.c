/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** frees all the nodes from a dllist
*/

#include <stdlib.h>
#include "dllists_obj.h"

void dllist_free_list(dllist_t *dllist)
{
    node_t *next;
    node_t *current;

    if (!dllist || dllist->len == 0 || !dllist->head || !dllist->head)
        return;
    current = dllist->head;
    while (current) {
        free(current->data);
        next = current->next;
        free(current);
        current = next;
    }
    dllist->len = 0;
    dllist->head = NULL;
    dllist->tail = NULL;
}