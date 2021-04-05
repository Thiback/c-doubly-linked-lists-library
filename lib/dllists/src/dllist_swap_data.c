/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** swaps two nodes of a doubly linked list.
*/

#include "dllists_obj.h"
#include <criterion/logging.h>

int dllist_swap_data(dllist_t *dllist, size_t posa, size_t posb)
{
    node_t *target_1 = NULL;
    node_t *target_2 = NULL;
    void *tmp = NULL;

    if (!dllist || dllist->len == 0 ||
        dllist->len <=  posa || dllist->len <= posb)
        return (84);
    if (posa == posb)
        return (0);
    else if (posa < posb) {
        posa = posa + posb;
        posb = posa - posb;
        posa = posa - posb;
    }
    target_1 = dllist_get_node_at(dllist, posa);
    target_2 = dllist_get_node_at(dllist, posb);
    tmp = target_2->data;
    target_2->data = target_1->data;
    target_1->data = tmp;
    return (0);
}