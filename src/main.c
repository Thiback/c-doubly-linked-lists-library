/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** Makefile of the library
*/

#include "dllists_obj.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void *my_putstr(void *data)
{
    write(1, data, strlen((char *)data));
    write(1, "\n", 1);
    return (NULL);
}

int main(void)
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu"};
    char **data2;
    dllist_t *dllist2;

    dllist.insert(&dllist, strdup(data[0]), 0);
    dllist.insert(&dllist, strdup(data[2]), 1);
    dllist.insert(&dllist, strdup(data[1]), 1);
    dllist.callback(&dllist, my_putstr);
    dllist.delete(&dllist);
    data2 = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; ++i)
        data2[i] = strdup(data[i]);
    dllist2 = array_to_dllist((void **)data2, 3);
    dllist2->reverse(&dllist);
    dllist2->swap(dllist2, 1, 2);
    dllist.delete(dllist2);
    free(data2);
    free(dllist2);
    return (0);
}