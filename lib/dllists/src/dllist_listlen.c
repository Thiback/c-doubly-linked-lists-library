/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** returns the length of the dllist. 0 if empty or if dllist == NULL
*/

#include <stdlib.h>
#include "dllists_obj.h"

size_t dllist_listlen(dllist_t *dllist)
{
    if (dllist == NULL)
        return (0);
    return (dllist->len);
}