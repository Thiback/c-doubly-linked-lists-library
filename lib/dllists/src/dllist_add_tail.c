/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** adds a node to a doubly linked list.
*/

#include <stdlib.h>
#include "dllists_obj.h"

static int at_add_first_node(dllist_t *list, void *data)
{
    if ((list->head = malloc(sizeof(node_t))) == NULL)
        return (84);
    list->head->next = NULL;
    list->head->prev = NULL;
    list->head->data = data;
    list->tail = list->head;
    list->len += 1;
    return (0);
}

int dllist_add_tail(dllist_t *list, void *data)
{
    node_t *tmp;

    if (!list || !data)
        return (84);
    if (list->len == 0)
        return (at_add_first_node(list, data));
    tmp = list->tail;
    if ((list->tail = malloc(sizeof(node_t))) == NULL) {
        list->tail = tmp;
        return (84);
    }
    tmp->next = list->tail;
    list->tail->next = NULL;
    list->tail->prev = tmp;
    list->tail->data = data;
    list->len += 1;
    return (0);
}