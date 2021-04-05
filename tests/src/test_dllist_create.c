/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** Unit tests for the "add_dllist_head" function.
*/

#include "criterion/criterion.h"
#include "criterion/logging.h"
#include "dllists_obj.h"

Test(dllist_create, single_call,
.description="Creation of a dllist")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.len, 0);
    cr_assert_eq(mylist.head, NULL);
    cr_assert_eq(mylist.tail, NULL);
}