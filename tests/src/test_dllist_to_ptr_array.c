/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_to_ptr_array" unit tests.
*/

#include <criterion/criterion.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(to_ptr_array, null_dllist_ptr,
.description="call with a NULL parameter")
{
    cr_assert_eq(dllist_to_ptr_array(NULL), NULL);
}

Test(to_ptr_array, single_node_dllist,
.description="call with a single node dllist")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one"};
    void **ptr_array = NULL;

    for (register int i = 0; i < 1; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data[i])), 0);
    ptr_array = dllist_to_ptr_array(&dllist);
    cr_assert_not_null(ptr_array);
    for (register int i = 0; i < 1; ++i)
        cr_assert_str_eq(ptr_array[i], data[i]);
}

Test(to_ptr_array, ten_node_dllist,
.description="ten node dllist")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"un", "deux", "trois", "quatre", "cinq",
                    "six", "sept", "huit", "neuf", "dix"};
    void **ptr_array = NULL;

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data[i])), 0);
    ptr_array = dllist_to_ptr_array(&dllist);
    cr_assert_not_null(ptr_array);
    for (register int i = 0; i < 10; ++i)
        cr_assert_str_eq(ptr_array[i], data[i]);
}