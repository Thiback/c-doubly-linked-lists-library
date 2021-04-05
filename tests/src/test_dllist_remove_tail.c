/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_remove_tail" unit tests.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(dllist_remove_tail, null_dllist_ptr,
.description="call with a NULL parameter")
{
    cr_assert_eq(dllist_remove_tail(NULL), 84);
}

Test(dllist_remove_tail, invalid_len,
.description="dllist has a length member of 0")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.remove_tail(&dllist), 84);
}

Test(dllist_remove_tail, null_tail)
{
    dllist_t dllist = dllist_create();

    dllist.len = 1;
    cr_assert_eq(dllist.remove_tail(&dllist), 84);
}

Test(dllist_remove_tail, three_node_dllist_tail_removal, .init=cr_redirect_stdout,
.description="single call on a single node dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("he")), 0);
    cr_assert_eq(dllist.remove_tail(&dllist), 0);
    cr_assert_eq(dllist.len, 2);
    print(&dllist);
    cr_assert_stdout_eq_str("he\nho\n");
}

Test(dllist_remove_tail, single_node_dllist_tail_removal, .init=cr_redirect_stdout,
.description="single call on a single node dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.remove_tail(&dllist), 0);
    cr_assert_eq(dllist.remove_tail(&dllist), 84);
    cr_assert_eq(dllist.len, 0);
    cr_assert_null(dllist.tail);
    cr_assert_null(dllist.head);
}

Test(dllist_remove_tail, full_list_destruction,
.description="deleting a dllist of 10 nodes")
{
    dllist_t dllist = dllist_create();
    char data[1] = {'a'};
    char *list_data;

    for (register int i = 0 ; i < 10 ; ++i) {
        cr_assert_eq(dllist.len, i);
        cr_assert_eq(dllist.add_head(&dllist, strdup(data)), 0);
        data[0] += 1;
        cr_assert_eq(dllist.len, i + 1);
    }
    for (register int i = 0 ; i < 10 ; ++i) {
        list_data = (char *)dllist.tail->data;
        cr_assert_eq(list_data[0], 97 + i);
        list_data = (char *)dllist.head->data;
        cr_assert_eq(list_data[0], 'j');
        cr_assert_eq(dllist.remove_tail(&dllist), 0);
        cr_assert_eq(dllist.len, 10 - (i + 1));
    }
    cr_assert_null(dllist.head);
    cr_assert_null(dllist.tail);
    cr_assert_eq(dllist.len, 0);
}