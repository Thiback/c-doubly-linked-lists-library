/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** ""dllist_get_data_at" unit tests."
*/

#include "dllists_obj.h"

void *dllist_get_data_at(dllist_t *dllist, size_t pos)
{
    node_t *target = dllist_get_node_at(dllist, pos);

    if (target == NULL)
        return (NULL);
    return (target->data);
}