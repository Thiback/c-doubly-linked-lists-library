/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** changes the list contents to match those from the specified array pointer
*/

#include <stdlib.h>
#include "dllists_obj.h"

dllist_t *array_to_dllist(void **array, size_t array_len)
{
    dllist_t *result;

    if (!array)
        return (NULL);
    if ((result = malloc(sizeof(dllist_t))) == NULL)
        return (NULL);
    *result = dllist_create();
    for (register size_t i = 0; i < array_len; ++i)
        if (result->add_tail(result, array[i]) != 0) {
            result->delete(result);
            free(result);
            return (NULL);
        }
    return (result);
}