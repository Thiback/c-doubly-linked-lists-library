/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "free_list" unit tests.
*/

#include <criterion/criterion.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(free_list, null_dllist,
.description="call with a null dllist pointer")
{
    dllist_free_list(NULL);
}

Test(free_list, empty_dllist,
.description="call on an empty dllist")
{
    dllist_t dllist = dllist_create();

    dllist.delete(&dllist);
}

Test(free_list, bad_len,
.description="call on a dllist with inaccurate length")
{
    dllist_t dllist = dllist_create();

    dllist.len = 1;
    dllist.delete(&dllist);
}

Test(free_list, null_head,
.description="call on a dllist with a valid head but len of 0")
{
    dllist_t dllist = dllist_create();

    dllist.add_head(&dllist, strdup("toto"));
    dllist.len = 0;
    dllist.delete(&dllist);
}

Test(free_list, single_node_list,
.description="call on a dllist with a single node")
{
    dllist_t dllist = dllist_create();

    dllist.add_head(&dllist, strdup("toto"));
    dllist.delete(&dllist);
    cr_assert_null(dllist.head);
    cr_assert_null(dllist.tail);
    cr_assert_eq(dllist.len, 0);
}

Test(free_list, two_node_list,
.description="call on a dllist with two nodes")
{
    dllist_t dllist = dllist_create();

    dllist.add_head(&dllist, strdup("toto"));
    dllist.add_head(&dllist, strdup("tata"));
    dllist.delete(&dllist);
    cr_assert_null(dllist.head);
    cr_assert_null(dllist.tail);
    cr_assert_eq(dllist.len, 0);
}