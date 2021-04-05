/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** adds a node to a doubly linked list.
*/

#include <stdlib.h>
#include "dllists_obj.h"

static int ah_add_first_node(dllist_t *list, void *data)
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

int dllist_add_head(dllist_t *list, void *data)
{
    node_t *tmp;

    if (!list || !data)
        return (84);
    if (list->len == 0)
        return (ah_add_first_node(list, data));
    tmp = list->head;
    if ((list->head = malloc(sizeof(node_t))) == NULL) {
        list->head = tmp;
        return (84);
    }
    tmp->prev = list->head;
    list->head->next = tmp;
    list->head->prev = NULL;
    list->head->data = data;
    list->len += 1;
    return (0);
}