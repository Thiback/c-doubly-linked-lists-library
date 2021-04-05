/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** iterates and passes the data pointer from the list to a specified function.
*/

#include "dllists_obj.h"

int dllist_iterate_with_callback(dllist_t *dllist, void *(_callback)(void *))
{
    node_t *current;
    int *callback_return = 0;

    if (!dllist || !_callback)
        return (84);
    else if (dllist->len == 0)
        return (0);
    current = dllist->head;
    while (current) {
        callback_return =  _callback(current->data);
        if (callback_return != 0)
            return (*callback_return);
        current = current->next;
    }
    return (0);
}